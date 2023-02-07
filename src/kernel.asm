use32
org 0x100000;this is where we are loaded
jmp start32
FLAGS_PAGE_ALIGN = 1 SHL 0
FLAGS_FLAT = 1 SHL 16

MAGIC = 0x1BADB002
FLAGS =   FLAGS_FLAT or FLAGS_PAGE_ALIGN


align 4
mheader:
magic dd MAGIC
flags dd FLAGS
checksum dd -(MAGIC+FLAGS)

headeraddr dd mheader
loadaddr dd 0x100000
loadend dd dataend
bssend dd 0;there is no BSS
jmpaddr dd start32

start32:;the start of the 32 bit code of the kernel where we set up for long mode
cli


incl:
dataend: