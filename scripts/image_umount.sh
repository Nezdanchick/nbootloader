#!/bin/bash

MNT=/mnt

# super user required
sudo umount $MNT
sudo losetup -d $DEVICE