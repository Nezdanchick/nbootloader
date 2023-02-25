#!/bin/bash

BIN=../bin
LOADER=$BIN/kernel.bin
IMG=../img
MODULES="multiboot2 boot"

bash build.sh

mkdir -p $IMG/boot/grub

cp ../config/grub.cfg $IMG/boot/grub
cp $BIN/kernel.elf $IMG/boot/kernel

grub-mkrescue $IMG --output=$BIN/image.iso \
--product-name="RandOS" \
--product-version=0.0.1 \
--directory=/usr/lib/grub/i386-pc \
--install-modules="$MODULES" \
--compress=xz \
--fonts="" \
--themes="" \
--locales=""