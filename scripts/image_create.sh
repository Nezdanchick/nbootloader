#!/bin/bash

BIN=../bin
LOADER=$BIN/boot.bin
DEVICE=/dev/loop12

bash clean.sh
bash build.sh

# create floppy
dd if=/dev/zero of=$BIN/image.img bs=512 count=2880
# write bootsector
dd status=noxfer conv=notrunc if=$LOADER of=$BIN/image.img

# format floppy to FAT12
# super user required
sudo losetup -d $DEVICE
sudo losetup -P $DEVICE $BIN/image.img
sudo mkfs.fat --offset 1 -F 12 -n REDOS $DEVICE
sudo losetup -d $DEVICE
