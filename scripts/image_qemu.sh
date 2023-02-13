#!/bin/bash

BIN=../bin
BOOT=$BIN/image.img

MEM=4M # minimum - 1009kb of ram

qemu-system-x86_64 \
-drive file=$BOOT,format=raw,index=0,media=disk \
-m $MEM \
-enable-kvm \
-audiodev pa,id=snd0 -machine pcspk-audiodev=snd0