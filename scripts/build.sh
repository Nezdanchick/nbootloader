#!/bin/bash

ROOT=../
SRC=$ROOT/src
BIN=$ROOT/bin
FILE=$1
FORMAT=elf64
LIB=

if [ $FILE == ]  ; then
    FILE=kernel
fi

mkdir -p $ROOT/bin/
nasm $SRC/$FILE.asm -o $BIN/entry.o -f $FORMAT -i $ROOT/src
clang -target x86_64-unknown-none -c -nostdlib -nodefaultlibs -ffreestanding \
-I $ROOT/src \
-O3 -Wall -Wextra -fno-exceptions \
-o $BIN/main.o \
$SRC/kernel.cpp

ld -T $ROOT/config/linker.ld -m elf_x86_64 -o $BIN/kernel.elf \
$BIN/entry.o $BIN/main.o $LIB