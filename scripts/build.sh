#!/bin/bash

ROOT=../
SRC=$ROOT/src
BIN=$ROOT/bin

fasm $SRC/boot.asm $BIN/boot.bin
