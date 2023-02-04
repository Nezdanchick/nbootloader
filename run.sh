#!/bin/bash

ROOT=$(realpath -s "./")

SCRIPTS=./scripts
BUILD=build.sh
RUN=qemu.sh

mkdir -p -v $ROOT/bin/
cd $SCRIPTS
if bash $BUILD ; then
    bash $RUN # if success
else
    read -p "Press Enter to continue..." # if fail reads line
fi