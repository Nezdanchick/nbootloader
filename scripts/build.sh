#!/bin/bash

ROOT=../
SRC=$ROOT/src
BIN=$ROOT/bin

fasm $SRC/$1.asm $BIN/$1.bin
