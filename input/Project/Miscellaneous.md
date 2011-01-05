title: Miscellaneous
sort: aaaaaaaaaa
category: 2
description: These are the projects that were done for classes and or are not as big as the ones above. This includes many pieces of sample code that I have written along with descriptions of what they do.
---
This page is dedicated to the small pieces of code that I have written over the years along with a description of what it is about. Please be aware that some of the projects here are still on-going and some of it was just not big enough to have its own project page.

# Intel Assembly

UAT was offering a course in Intel assembly, and for the class  we had to write our programs in a mixture of both C and inline assembly. However the instructor also was willing to let us write the programs in pure Intel assembly. At the time I really wanted to learn about Intel assembly and thus downloaded and compiled nasm for FreeBSD and learned how to interact with the kernel (to write messages to stdout) how the stack was created, how function calls interacted with each other.

## addnumbers.asm

Using the knowledge I created a program that is capable of adding two numbers together if they are passed as the first and second argument. This code still has the unfortunate side effect, that as soon as the numbers add up to anything bigger than the default integer size (4 bytes, 32 bits) it will give a wrong answer.

[Download code][1]

## hextobinary.asm

The class  was also required to write a piece of code that converted a two's compliment hex value to binary. This was also an interesting challenge, and I found that when I allocated memory in the .bss of the program, depending on how the OS laid out the stack in memory the input of the program could be much bigger than it was originally intended to be.

[Download code][2]

# SX28 Assembly Boe-Bot

The Boe-Bot from Parallax is a BASIC Stamp device, it is a robot that can be programmed using the PBASIC programming language. For one of our classes we were required to write a simple Boe-Bot like program in assembly which used whiskers and light sensors to do obstacle avoidance.

[Download code][3]

[1]: /Project/code/addnumbers.asm "Source code for the Intel assembly addnumbers.asm"
[2]: /Project/code/converthextobinary.asm "Source code for the Intel assembly"
[3]: /Project/code/boebot.src "Source code for the SX28 assembly"