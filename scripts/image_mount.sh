#!/bin/bash

BIN=../bin
DEVICE=/dev/loop9
MNT=/mnt

cd $BIN

# super user required
sudo umount $MNT
sudo losetup -d $DEVICE
sudo losetup -P $DEVICE image.img
sudo mount $DEVICE $MNT