#!/bin/bash

BIN=../bin
LOADER=boot.bin

dd if=/dev/zero of=$BIN/image.img bs=512 count=2880
dd status=noxfer conv=notrunc if=$BIN/$LOADER of=$BIN/image.img