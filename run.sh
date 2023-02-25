#!/bin/bash

ROOT=$(realpath -s "./")

SCRIPTS=./scripts
BUILD=build.sh
ISO=image_grub.sh
RUN=image_qemu.sh
FILE=$1

cd $SCRIPTS

if bash $BUILD && bash $ISO ; then
    bash $RUN $FILE
else
    read -p "Press Enter to continue..."
fi