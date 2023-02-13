ENTRY(_start)
SECTIONS
{

	.text: 0x100000 :
	{
        /* link the multiboot struct here */
        . = ALIGN(8);
        KEEP(*(.multiboot))
        /* place all of your code afterwards */
        *(.text)
    }

    .data :
    {
        data = .; _data = .; __data = .;
        *(.data)
        *(.rodata)
        . = ALIGN(4096);
    }

    .bss :
    {
        bss = .; _bss = .; __bss = .;
        *(.bss)
        . = ALIGN(4096);
    }

    end = .; _end = .; __end = .;
}