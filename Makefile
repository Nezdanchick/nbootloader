ARCH=i386
#i386 x86_64
ASM_FORMAT=elf32
#elf32 elf64
LD_FORMAT=elf_$(ARCH)
#elf_i386 elf_x86_64
CC_TARGET=$(ARCH)
#i386-unknown-none x86_64-unknown-none

LD=ld
#x86_64-linux-gnu-ld
CC=clang
ASM=nasm
CC_FLAGS=-nostdlib -nodefaultlibs -ffreestanding -fno-exceptions -I$(INCLUDE) \
 -Wall -Wextra -target $(CC_TARGET) -c
ASM_FLAGS=-f $(ASM_FORMAT) -i $(INCLUDE)
LD_FLAGS=-m $(LD_FORMAT) --nmagic -T ./config/linker.ld

CP:=cp
RM:=rm -rf
MKDIR:=mkdir -p

BIN=kernel.bin
CFG=./config/grub.cfg
ISO_PATH:=./bin/iso
BOOT_PATH=$(ISO_PATH)/boot
GRUB_PATH=$(BOOT_PATH)/grub
INCLUDE=./include

all: iso run

build: build-bootloader build-kernel build-lib
	$(LD) $(LD_FLAGS) -o ./bin/$(BIN) \
	 $(wildcard ./bin/*.o)

build-bootloader: ./kernel/boot/boot.asm
	$(MKDIR) ./bin/iso/boot/grub
	$(ASM) $(ASM_FLAGS) ./kernel/boot/*.asm -o ./bin/bootloader.o

build-kernel: ./kernel/kernel.c
	$(CC) $(CC_FLAGS) --output ./bin/kernel.o ./kernel/kernel.c

build-lib:
	$(CC) $(CC_FLAGS) $(wildcard ./lib/*/*.c) $(wildcard ./lib/*.c)
	mv *.o ./bin/
iso: build
	$(MKDIR) $(ISO_PATH)
	$(CP) ./bin/$(BIN) $(BOOT_PATH)
	$(CP) $(CFG) $(GRUB_PATH)
	grub-file --is-x86-multiboot2 $(BOOT_PATH)/$(BIN)
	grub-mkrescue $(ISO_PATH) --output=image.iso \
	--product-name="RandOS" \
	--product-version=0.1.1 \
	--directory=/usr/lib/grub/i386-pc \
	--install-modules="multiboot2 boot" \
	--compress=xz \
	--fonts="" \
	--themes="" \
	--locales=""

run:
	qemu-system-$(ARCH) \
	-drive file=image.iso,format=raw,index=0,media=disk \
	-m 128M \
	-enable-kvm \
	-audiodev pa,id=snd0 -machine pcspk-audiodev=snd0 \
	-no-reboot

clean:
	$(RM) ./bin *.iso *.o