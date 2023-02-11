#!/bin/bash

ROOT=../
SRC=$ROOT/src
BIN=$ROOT/bin
FILE=$1

fasm $SRC/$FILE.asm $BIN/$FILE.bin
