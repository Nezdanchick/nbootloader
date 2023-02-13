#!/bin/bash

BIN=../bin
LOADER=$BIN/kernel.bin
IMG=../img

mkdir -p $BIN
sudo cp ../config/grub.cfg $IMG/boot/grub

sudo cp $BIN/kernel.elf $IMG/boot/kernel
grub-mkrescue --output=$BIN/image.img $IMG