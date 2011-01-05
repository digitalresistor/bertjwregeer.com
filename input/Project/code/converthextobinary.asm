; File: converthextobinary.asm
; Bert JW Regeer
; 
; 2008-03-02
; 
; Function:
;       Convert a twos compliment hex number to binary
;
; Known Limitations:
;       Really, we can do a max of 16 characters, however since answer is located in .bss, for some reason the OS
;       does not kill the application when you keep writing beyond the 64 bytes I have reserved, so whatever length
;       you want works :P
;
 
section .data

        ; Define some strings that are going to be used throughout the program

        ; This string is to let the user know they failed to provide the proper amount of arguments.
args    db      "Program hex2bin: ", 0xa, 0x9, "hex2bin <number>", 0xa, 0x9, "Argument <number> is required", 0xa, 0x9, "Please input the value without prepending a 0x. [0xF] is invalid, [F] is valid.", 0xa
largs   equ     $ - args

        ; This string contains part of the output that we are going to send to the terminal. The last two
        ; bytes will be filled automatically by the program, before it is output to stdout.
msg     db      'Answer: ',     0
lmsg    equ     $ - msg

section .bss
        ; This is where I am going to store the actual ASCII version of the string which will then be output!
answer  resb    64

section .text
global start                            ; Linker defined entry point. Mac OS X this is start. 
global _start                           ; FreeBSD and others _start.


_start:
start:
        push    ebp                     ; 
        mov     ebp, esp                ; Set up the stack frame

        mov     ecx, [ebp + 4]          ; Get argc, we check if it set to at least 2
        mov     edx, ebp                ; Put the base pointer into edx, so we can use that in 
                                        ; our dereferences coming up
        add     edx, 8                  ; Add 8. We want to skip ebp and argc

        cmp     ecx, 2                  ; Check if we have at least 2 arguments to the program. 
        jl      exit                    ; If the value in ecx is less than 3, jump to exit

        mov     eax, [edx + 1 * 4]      ; Move the pointer to the character array into eax
        push    eax                     ; Push eax onto the stack
        push    answer                  ; Push the pointer to num onto the stack
        call    ctoib                   ; Call my char to int function
        add     esp, byte 8             ; Put the stack pointer back to where it was.

        push    dword lmsg              ; Push the length of the string
        push    msg                     ; Push the location of the string in memory
        push    dword 0x1               ; Push the file descriptor to write to
        mov     eax,4                   ; Move the syscall number into eax
        push    eax                     ; Push the syscall onto the stack
        int     0x80                    ; Interrupt 80, go to kernel
        add     esp, byte 16            ; Clean up the stack
 
        push    answer                  ; Push answer onto the stack
        call    len                     ; Get it's length

        push    eax                     ; Push the length onto the stack
        push    answer                  ; Push the location of answer
        push    dword 0x1               ; Push the file descriptor to write to
        mov     eax,4                   ; Push the syscall number into eax
        push    eax                     ; Push the syscall onto the stack
        int     0x80                    ; Interrupt 80, go to kernel
        add     esp, byte 16            ; Clean up the stack

        jmp     done                    ; Program is done. Jump to done

exit:
        ; This label is jumped to when we want to exit the program and let the user know how
        ; to run the program. Like for instance what paramaters to send the program.
                                        ; Call sys_write
        push    dword largs             ; Push the length of the string
        push    dword args              ; Push the location of the string in memory
        push    dword 0x1               ; Push the file descriptor to write to
        mov     eax,4                   ; Move the syscall number into eax
        push    eax                     ; Push the syscall onto the stack
        int     0x80                    ; Interrupt 80, go to kernel
        add     esp, byte 16            ; Clean up the stack

done:
        ; This is the label we jump to when we want to exit the program, we set the exit code
        ; to 0.
                                        ; Call sys_exit
        push    dword 0x0               ; Push the value to return to the operating system
        mov     eax,1                   ; Move the syscall number into eax
        push    eax                     ; Push the syscall onto the stack
        int     0x80                    ; Interrupt 80, go to kernel

        ; We never return to this function, so no need to clean the stack. :P

ctoib:
        ; char to binary. We actually convert entire character array's to binary.
        ;
        ; We get two paramaters on the stack. The first one we grab is the pointer to the place to store
        ; the number. The second is the pointer to the character array.

        push    ebp                     ; Push the old base pointer onto the stack
        mov     ebp, esp                ; Create a new base pointer
        push    esi                     ; Store all the original registers
        push    edi
        push    eax
        push    ebx
        push    ecx
        push    edx

        mov     eax, [ebp + 12]         ; Move the pointer to the character array into eax
        push    eax                     ; Push the pointer to the character array onto the stack
        call    len                     ; Call the string length function
        add     esp, byte 4             ; Reclaim the space we lost when we pushed eax onto the stack

        mov     ebx, [ebp + 8]          ; This is where we are going to store the numbers
        mov     esi, [ebp + 12]         ; This is the pointer to the character array
        mov     ecx, eax                ; move with extended zero eax, it contains the return value from the length function
        xor     edi, edi                ; Clean up edi

        ctoi_loop:
        movzx   eax, byte [esi + edi]   ; Move the character into eax
        movsx   eax, al                 ; We just want the lower part of the character

        cmp     eax, 0x30               ; Check to see if the value they gave us is below the digits in the ascii table
        jnae    exit                    ; Hard exit the program
        cmp     eax, 0x39               ; Check if the value is within the digits range on the ASCII table
        jnle    ctoi_high               ; If not, jump to ctoi_high

                                        ; Cool, the above two checks are false, so it is a valid number

        sub     eax, 0x30               ; Subtract 0x30, ASCII 0 so that it is an actual number 
        jmp     ctoi_cont

        ctoi_high:
        cmp     eax, 0x41               ; Check if it is a valid character, in this case equal to A or more
        jnae    exit 
        cmp     eax, 0x46               ; Check if the value in EAX is larger than F in the ascii table
        jnle    ctoi_higher             ; Jump to ctoi_higher

                                        ; Cool the above two checks failed
        sub     eax, 0x37               ; Subtract 0x37, ASCII 'A' turns to 11
        jmp     ctoi_cont

        ctoi_higher:
        cmp     eax, 0x61               ; Check if this is a valid character, in this case 'a'
        jnae    exit                    ; This check fails, exit
        cmp     eax, 0x66               ; Check if the value is less than or equal to 'f'
        jnle    exit                    ; If we fail it means the value is higher yet, exit

        sub     eax, 0x57               ; Subtract 0x57, ASCII 'a' turns to 11

        ctoi_cont:

        push    ebx                     ; Push the location of answer to the function
        push    eax                     ; Push the number to the function
        call    itob                    ; Call our function to convert from the integer to binary
        add     esp, byte 8             ; Clean up after ourselves!

        add     ebx, 4                  ; We advance the pointer into ebx by 4
        inc     edi                     ; Increase the counter
        loop ctoi_loop                  ; Loop into cx is 0

        mov     [ebx], byte 0xa         ; Add a newine character

        add     esp, byte 4
        pop     edx                     ; Restore all the registers
        pop     ecx
        pop     ebx
        pop     eax
        pop     edi
        pop     esi
        mov     esp, ebp                ; Make esp the original base pointer again
        pop     ebp                     ; Pop the original base pointer into the register
        ret                             ; Return caller

itob:
        push    ebp                     ; Setup a new stack frame
        mov     ebp, esp
        push    eax                     ; Save the registers
        push    ebx
        push    ecx
        push    edx

        mov     eax, [ebp + 8]          ; eax is going to contain the integer
        mov     edx, [ebp + 12]         ; Put a pointer to answer into ecx

        shl     eax, 28                 ; Shift the value in al to the top bits. This way we can use the carry flag
        mov     cl, 4                   ; This is how many times we want to loop

        itob_loop:
        shl     eax, 1                  ; Shift al left by 1
        jc      itob_carry              ; Jump if the carry bit is set

                                        ; Carry bit is not set
        mov     [edx], byte 0x30        ; So we add a 0 to the output
        jmp     itob_cont

        itob_carry:
        mov     [edx], byte 0x31        ; We add a 1 to the output array

        itob_cont:
        inc edx
        loop itob_loop                  ; Loop until cx is empty

        pop     edx                     ; Restore registers
        pop     ecx
        pop     ebx
        pop     eax
        mov     esp, ebp
        pop     ebp
        ret

len:
        ; Returns the length of a string. The string has to be null terminated. Otherwise this function
        ; will fail miserably. 
        ; Upon return. eax will contain the length of the string.

        push    ebp                     ; Save the previous stack pointer. We restore it on return
        mov     ebp, esp                ; We setup a new stack frame
        push    ecx
        push    edi

        mov     ecx,  [ebp + 8]         ; Move the pointer to eax; we want an offset of one, to jump over the return address

        mov     edi, 0                  ; Set the counter to 0. We are going to increment this each loop

        len_loop:                       ; Just a quick label to jump to
        movzx   eax, byte [ecx + edi]   ; Move the character to eax.
        movsx   eax, al                 ; Move al to eax. al is part of eax.
        inc     di                      ; Increase di.
        cmp     eax, 0                  ; Compare eax to 0.
        jnz     len_loop                ; If it is not zero, we jump back to len_loop and repeat.

        dec     di                      ; Remove one from the count

        movzx   eax, di

        pop     edi
        pop     ecx                     ; Restore registers
        mov     esp, ebp                ; Set esp back to what ebp used to be.
        pop     ebp                     ; Restore the stack frame
        ret                             ; Return to caller