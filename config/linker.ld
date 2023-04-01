ENTRY(start)
SECTIONS
{
    .text 0x1000000 :
    {
        code = .; _code = .; __code = .;
        . = ALIGN(4);
        KEEP(*(.multiboot))
        *(.text)
    }

    .data :
    {
        data = .; _data = .; __data = .;
        *(.data)
        *(.rodata)
        . = ALIGN(4);
    }

    .bss :
    {
        bss = .; _bss = .; __bss = .;
        *(.bss)
        . = ALIGN(4);
    }

    end = .; _end = .; __end = .;
}