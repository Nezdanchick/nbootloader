# RandOS

RandOS is small operating system for pc.
I hope this project never die.

# How to build

To build my operating system you need these programs:

```sh
sudo apt install make grub-pc-bin clang nasm binutils
# binutils needs for ld, you can use crosscompiler
# x86_64-linux-gnu-ld
```

To run RandOS you need qemu:

```sh
sudo apt install qemu-system-i386 qemu-system-x86_64
```

Make commands:

```sh
# build kernel
make build
```

```sh
# deploy iso
make iso
```

```sh
# run iso in qemu
make run
```

```sh
# build, deploy and run
make
```

# WARNING

This project is under development, so at this stage I can change everything: from the code to the name of the project
