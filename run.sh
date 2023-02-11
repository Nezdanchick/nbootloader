#!/bin/bash

ROOT=$(realpath -s "./")

SCRIPTS=./scripts
BUILD=build.sh
RUN=qemu.sh
FILE=$1

mkdir -p -v $ROOT/bin/
cd $SCRIPTS

if [$FILE == ""] ; then
    FILE="boot"
fi

if bash $BUILD $FILE ; then
    bash $RUN $FILE
else
    read -p "Press Enter to continue..."
fi