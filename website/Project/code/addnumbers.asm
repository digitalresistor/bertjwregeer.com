; File: addnumbers.asm
; Bert JW Regeer
; 
; 2008-01-27
; 
; Function:
;	Add numbers together that are provided as arguments to the program in argv[1] and argv[2].
;
; Known limitations:
;	Floating point numbers will not work.
;	Any input that is larger than an integer will cause overflows, and thus will not work.
 
section .data

	; Define some strings that are going to be used throughout the program

	; This string is to let the user know they failed to provide the proper amount of arguments.
args	db	"Program addnumbers: ", 0xa, 0x9, "addnumbers  ", 0xa, 0x9, "Arguments 1 and 2 are required.", 0xa, 0x9, "Anything that will cause addition to overflow an int (2,147,483,647), will fail! :P", 0xa
largs	equ	$ - args

	; This string contains part of the output that we are going to send to the terminal. The last two
	; bytes will be filled automatically by the program, before it is output to stdout.
msg	db	'Answer: ',	0
lmsg	equ	$ - msg

num1	dd	0
num2	dd	0

section .bss
	; This is where I am going to store the output of my conversion from an integer to a char
answer	resb	64

section .text
global start				; Linker defined entry point. Mac OS X this is start. 
global _start				; FreeBSD and others _start.


_start:
start:
	push	ebp			; 
	mov	ebp, esp 		; Set up the stack frame

	mov	ecx, [ebp + 4]		; Get argc, we check if it set to at least 3
	mov	edx, ebp		; Put the base pointer into edx, so we can use that in 
					; our dereferences coming up
	add	edx, 8			; Add 8. We want to skip ebp and argc

	cmp	ecx, 3			; Check if we have at least 3 arguments to the program. 
					; At least two arguments are required, and the 3rd one is 
					; the name of the program
	jl	exit			; If the value in ecx is less than 3, jump to exit

	mov	esi, 1			; Set the index to 1
	
	mov	eax, [edx + esi * 4]	; Move the pointer to the character array into eax
	push	eax			; Push eax onto the stack
	push	num1			; Push the pointer to num1 onto the stack
	call	ctoi			; Call my char to int function
	add	esp, byte 8		; Put the stack pointer back to where it was.

	inc	esi			; Increase the index
	
	mov	eax, [edx + esi * 4]	; Move the pointer to the character array into eax
	push	eax			; Push eax onto the stack
	push	num2			; Push the pointer to num2 onto the stack
	call	ctoi			; Call my char to int function
	add	esp, byte 8		; Put the stack pointer back to where it was.

	mov	eax, [num1]		; Move value stored in num1 into eax
	add	eax, [num2]		; Add num2 to eax, this will now be stored in eax

	push	eax			; Push the new calculated number onto the stack
	call	itoa			; Convert the integer to a character array

	push	dword lmsg		; Push the length of the string
	push	msg			; Push the location of the string in memory
	push	dword 0x1		; Push the file descriptor to write to
	mov	eax,4			; Move the syscall number into eax
	push	eax			; Push the syscall onto the stack
	int	0x80			; Interrupt 80, go to kernel
	add	esp, byte 16		; Clean up the stack
 
	push	answer			; Push answer onto the stack
	call	len			; Get it's length

	push	edi			; Push the length onto the stack
	push	answer			; Push the pointer to the character string onto the stack
	push	dword 0x1		; Push the file descriptor to write to
	mov	eax,4			; Push the syscall number into eax
	push	eax			; Push the syscall onto the stack
	int	0x80			; Interrupt 80, go to kernel
	add	esp, byte 16		; Clean up the stack

	jmp	done			; Program is done. Jump to done

exit:
	; This label is jumped to when we want to exit the program and let the user know how
	; to run the program. Like for instance what paramaters to send the program.
					; Call sys_write
	push	dword largs		; Push the length of the string
	push	dword args		; Push the location of the string in memory
	push	dword 0x1		; Push the file descriptor to write to
	mov	eax,4			; Move the syscall number into eax
	push	eax			; Push the syscall onto the stack
	int	0x80			; Interrupt 80, go to kernel
	add	esp, byte 16		; Clean up the stack

done:
	; This is the label we jump to when we want to exit the program, we set the exit code
	; to 0.
					; Call sys_exit
	push	dword 0x0		; Push the value to return to the operating system
	mov	eax,1			; Move the syscall number into eax
	push	eax			; Push the syscall onto the stack
	int	0x80			; Interrupt 80, go to kernel

	; We never return to this function, so no need to clean the stack. :P

ctoi:
	; char to i. We actually convert entire character array's to integers.
	;
	; We get two paramaters on the stack. The first one we grab is the pointer to the place to store
	; the number. The second is the pointer to the character array.

	push	ebp			; Push the old base pointer onto the stack
	mov	ebp, esp		; Create a new base pointer
	push	esi			; Store all the original registers
	push	eax
	push	ebx
	push	ecx	
	push	edx			; Push edx, so that we can overwrite it
	sub	esp, 4			; We get another storage space on the stack
	mov	[esp], dword 10		; This is the number we are going to multiply by

	mov	eax, [ebp + 12]		; Move the pointer to the character array into eax
	push	eax			; Push the pointer to the character array onto the stack
	call	len			; Call the string length versoin
	add	esp, byte 4		; Reclaim the space we lost when we pushed eax onto the stack
	
	mov	ebx, [ebp + 8]		; This is where we are going to store the numbers
	mov	esi, [ebp + 12]		; This is the pointer to the character array
	movzx	ecx, di			; move with extended zero edi.
	mov	edi, 0			; Clean up edi

	ctoi_loop:
	mov	eax, [ebx]		; Move the value stored in ebx into eax
	mul	dword [esp]		; Move it over a 10s place.
	mov	[ebx], eax		; Move the new number back into ebx

	movzx	eax, byte [esi + edi]	; Move the character into eax
	movsx	eax, al			; We just want the lower part of the character

	sub	eax, 0x30		; Subtract 0x30, ASCII 0 so that it is an actual number
	add	[ebx], eax		; Add the new number to the old number that has been multiplied by 10
	inc	edi			; Increase the counter
	loop ctoi_loop			; Loop into cx is 0

	add	esp, byte 4
	pop	edx			; Restore all the registers
	pop	ecx
	pop	ebx
	pop	eax
	pop	esi
	mov	esp, ebp		; Make esp the original base pointer again
	pop	ebp			; Pop the original base pointer into the register
	ret				; Return caller

itoa:
	; Recursive function. This is going to convert the integer to the character.
	push	ebp			; Setup a new stack frame
	mov	ebp, esp
	push	eax			; Save the registers
	push	ebx
	push	ecx
	push	edx

	mov	eax, [ebp + 8]		; eax is going to contain the integer
	mov	ebx, dword 10		; This is our "stop" value as well as our value to divide with
	mov	ecx, answer		; Put a pointer to answer into ecx
	push	ebx			; Push ebx on the field for our "stop" value

	itoa_loop:
	cmp	eax, ebx		; Compare eax, and ebx
	jl	itoa_unroll		; Jump if eax is less than ebx (which is 10)
	xor	edx, edx		; Clear edx
	div	ebx			; Divide by ebx (10)
	push	edx			; Push the remainder onto the stack
	jmp	itoa_loop		; Jump back to the top of the loop
	itoa_unroll:			
	add	al, 0x30		; Add 0x30 to the bottom part of eax to make it an ASCII char
	mov	[ecx], byte al		; Move the ASCII char into the memory references by ecx
	inc	ecx			; Increment ecx
	pop	eax			; Pop the next variable from the stack
	cmp	eax, ebx		; Compare if eax is ebx
	jne	itoa_unroll		; If they are not equal, we jump back to the unroll loop
					; else we are done, and we execute the next few commands
	mov	[ecx], byte 0xa		; Add a newline character to the end of the character array
	inc	ecx			; Increment ecx
	mov	[ecx], byte 0		; Add a null byte to ecx, so that when we pass it to our
					; len function it will properly give us a length

	pop	edx			; Restore registers
	pop	ecx
	pop	ebx
	pop	eax
	mov	esp, ebp		
	pop	ebp
	ret

len:
	; Returns the length of a string. The string has to be null terminated. Otherwise this function
	; will fail miserably. 
	; Upon return. edi will contain the length of the string.

	push	ebp			; Save the previous stack pointer. We restore it on return
	mov	ebp, esp		; We setup a new stack frame
	push	eax			; Save registers we are going to use. edi returns the length of the string
	push 	ecx
	
	mov	ecx,  [ebp + 8]		; Move the pointer to eax; we want an offset of one, to jump over the return address

	mov	edi, 0			; Set the counter to 0. We are going to increment this each loop

	len_loop:			; Just a quick label to jump to
	movzx	eax, byte [ecx + edi]	; Move the character to eax.
	movsx	eax, al			; Move al to eax. al is part of eax.
	inc	di			; Increase di.
	cmp	eax, 0			; Compare eax to 0.
	jnz 	len_loop		; If it is not zero, we jump back to len_loop and repeat.

	dec	di			; Remove one from the count

	pop	ecx			; Restore registers
	pop	eax
	mov	esp, ebp		; Set esp back to what ebp used to be.
	pop	ebp			; Restore the stack frame
	ret				; Return to caller