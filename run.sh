#!/bin/bash

ROOT=$(realpath -s "./")

SCRIPTS=./scripts
BUILD=build.sh
RUN=qemu.sh

mkdir -p -v $ROOT/bin/
cd $SCRIPTS
if bash $BUILD $1 ; then
    bash $RUN $1
else
    read -p "Press Enter to continue..."
fi