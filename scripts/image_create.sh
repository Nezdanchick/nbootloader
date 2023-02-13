#!/bin/bash

BIN=../bin
LOADER=$BIN/boot.bin
DEVICE=/dev/loop12
MNT=/mnt/image
IMG=../img

bash clean.sh
bash build.sh

# create floppy
dd if=/dev/zero of=$BIN/image.img bs=512 count=2880

# format floppy to ext4
# super user required
sudo mkfs -t ext4 -L RANDOS $BIN/image.img

# write bootsector
dd status=noxfer conv=notrunc if=$LOADER of=$BIN/image.img