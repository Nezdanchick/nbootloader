#!/bin/bash

MEM=4M # minimum - 1009kb of ram

BIN=../bin
FILE=$1
if [$FILE == ""] ; then
    FILE="boot"
fi
BOOT=$BIN/$FILE.bin

qemu-system-x86_64 \
-drive format=raw,file=$BOOT \
-audiodev pa,id=snd0 -machine pcspk-audiodev=snd0 \
-m $MEM \
-enable-kvm