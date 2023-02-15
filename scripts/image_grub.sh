#!/bin/bash

BIN=../bin
LOADER=$BIN/kernel.bin
IMG=../img

mkdir -p $BIN
cp ../config/grub.cfg $IMG/boot/grub

cp $BIN/kernel.elf $IMG/boot/kernel
grub-mkrescue --output=$BIN/image.iso $IMG