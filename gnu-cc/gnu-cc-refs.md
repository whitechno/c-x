GNU CC references
=================

<https://opensource.com/article/22/5/gnu-c-compiler>

<https://gcc.gnu.org/onlinedocs/gcc-14.2.0/gcc/Overall-Options.html>

```c
#include <stdio.h>
 
int main() {
 printf("Hello, GCC!\n");
  return 0;
}
```

```shell
gcc -o hellogcc hellogcc.c
```

There are actually four steps to compiling, even though GCC performs them
automatically in simple use-cases.

1. Pre-Processing: The GNU C Preprocessor (`cpp`) parses the headers (#include
   statements), expands macros (#define statements), and generates an
   intermediate file such as `hellogcc.i` with expanded source code.
2. Compilation: During this stage, the compiler converts pre-processed source
   code into assembly code for a specific CPU architecture. The resulting
   assembly file is named with a `.s` extension, such as `hellogcc.s` in this
   example.
3. Assembly: The assembler (`as`) converts the assembly code into machine code
   in an object file, such as `hellogcc.o`.
4. Linking: The linker (`ld`) links the object code with the library code to
   produce an executable file, such as `hellogcc`.

When running GCC, use the -v option to see each step in detail.

```shell
gcc -v -o hellogcc hellogcc.c
```

It can be useful to experience each step of compilation because, under some
circumstances, you don't need GCC to go through all the steps.

First, start the pre-processor, redirecting its output to `hellogcc.i`:

```shell
$ gcc -E hellogcc.c > hellogcc.i

$ ls
hellogcc.c  hellogcc.i
```

Take a look at the output file and notice how the pre-processor has included the
headers and expanded the macros.

Now you can compile the code into assembly. Use the `-S` option to set GCC just
to produce assembly code.

```shell
$ gcc -S hellogcc.c
or
$ gcc -S hellogcc.i

$ ls
hellogcc.c  hellogcc.i  hellogcc.s

$ cat hellogcc.s
```

Take a look at the assembly code to see what's been generated.

```assembly
        .section        __TEXT,__text,regular,pure_instructions
        .build_version macos, 14, 0     sdk_version 15, 2
        .globl  _main                           ## -- Begin function main
        .p2align        4, 0x90
_main:                                  ## @main
        .cfi_startproc
## %bb.0:
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset %rbp, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register %rbp
        subq    $16, %rsp
        movl    $0, -4(%rbp)
        leaq    L_.str(%rip), %rdi
        movb    $0, %al
        callq   _printf
        xorl    %eax, %eax
        addq    $16, %rsp
        popq    %rbp
        retq
        .cfi_endproc
                                        ## -- End function
        .section        __TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
        .asciz  "Hello, GCC!\n"

.subsections_via_symbols
```

To generate assembly code with clang in Intel syntax:

```shell
gcc -S -masm=intel hellogcc.c
```

Use the assembly code you've just generated to create an object file:

```shell
$ as -o hellogcc.o hellogcc.s
or
$ gcc -c hellogcc.c
or
$ gcc -c hellogcc.s

$ ls
hellogcc.c  hellogcc.i  hellogcc.o  hellogcc.s
```

And finally, linking:

```shell
gcc -o hellogcc hellogcc.o
```

All four in one command:

```shell
gcc -save-temps -o hellogcc hellogcc.c
```

### Some helpful utilities

Use the `file` utility to determine the type of file:

```shell
$ file hellogcc.c
hellogcc.c: c program text, ASCII text

$ file hellogcc.o
hellogcc.o: Mach-O 64-bit object x86_64

$ file hellogcc
hellogcc: Mach-O 64-bit executable x86_64
```

Use the `nm` utility to list symbol tables for object files:

```shell
$ nm hellogcc.o
0000000000000000 T _main
                 U _printf
```
