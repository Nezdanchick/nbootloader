#!/bin/bash

ROOT=../
SRC=$ROOT/src
BIN=$ROOT/bin
FILE=$1
FORMAT=elf64

if [ $FILE == "" ] ; then
    FILE=boot
    FORMAT=bin
fi

mkdir -p -v $ROOT/bin/
nasm $SRC/$FILE.asm -o $BIN/$FILE.o -f $FORMAT -i $ROOT/src
ld -T $ROOT/config/linker.ld -m elf_x86_64 -o $BIN/kernel.elf $BIN/$FILE.o

#i686-elf-g++ -c $SRC/kernel.cpp -o $BIN/kernel.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
#i686-elf-gcc -T $ROOT/config/linker.ld -o $BIN/kernel.elf -ffreestanding -O2 -nostdlib $BIN/$FILE.o -lgcc