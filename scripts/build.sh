#!/bin/bash

ROOT=../
SRC=$ROOT/src
BIN=$ROOT/bin
FILE=$1

if [$FILE == ""] ; then
    FILE="boot"
fi

mkdir -p -v $ROOT/bin/
fasm $SRC/$FILE.asm $BIN/$FILE.bin
