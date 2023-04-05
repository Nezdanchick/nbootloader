ARCH=i386
#i386 x86_64
LD_FORMAT=elf_$(ARCH)
#elf_i386 elf_x86_64
CC_TARGET=$(ARCH)
#i386-unknown-none x86_64-unknown-none
ASM_FORMAT=elf

LD=ld
#x86_64-linux-gnu-ld
CC=clang
ASM=nasm
CC_FLAGS=-nostdlib -nodefaultlibs -ffreestanding -fno-exceptions -I$(INCLUDE) \
 -Wall -Wextra -Werror -target $(CC_TARGET) -c
ASM_FLAGS=-f $(ASM_FORMAT) -i $(INCLUDE)
LD_FLAGS=-m $(LD_FORMAT) --nmagic -T ./config/linker.ld

CP:=cp
RM:=rm -rf
MKDIR:=mkdir -p

SRC=./src
KERNEL=core
CFG=./config/grub.cfg
ISO_PATH:=./bin/iso
KERNEL_PATH=$(ISO_PATH)/system
GRUB_PATH=$(ISO_PATH)/boot/grub
INCLUDE=$(SRC)/include

all: iso run

build: clean build-bootloader build-kernel build-lib
	$(LD) $(LD_FLAGS) -o ./bin/$(KERNEL) \
	 $(wildcard ./bin/*.o)

build-bootloader: $(SRC)/kernel/boot/boot.asm
	$(MKDIR) ./bin/iso/boot/grub
	$(ASM) $(ASM_FLAGS) $(SRC)/kernel/boot/*.asm -o ./bin/boot.o

build-kernel: $(SRC)/kernel/kernel.c
	$(CC) $(CC_FLAGS) $(wildcard $(SRC)/kernel/*/*.c) $(wildcard $(SRC)/kernel/*.c)
	mv *.o ./bin/

build-lib:
	$(CC) $(CC_FLAGS) $(wildcard $(SRC)/lib/*/*.c) $(wildcard $(SRC)/lib/*.c)
	mv *.o ./bin/
	
iso: build
	$(MKDIR) $(KERNEL_PATH)
	$(MKDIR) $(GRUB_PATH)
	$(CP) ./bin/$(KERNEL) $(KERNEL_PATH)
	$(CP) $(CFG) $(GRUB_PATH)
	grub-file --is-x86-multiboot2 $(KERNEL_PATH)/$(KERNEL)
	grub-mkrescue $(ISO_PATH) --output=./bin/image.iso \
	--product-name="RandOS" \
	--directory=/usr/lib/grub/i386-pc \
	--install-modules="multiboot2 boot" \
	--compress=xz \
	--fonts="" \
	--locales="" \
	--themes=""

run: # minimum 32M
	qemu-system-$(ARCH) \
	-m 32M \
	-no-reboot \
	-enable-kvm \
	-d guest_errors \
	-audiodev pa,id=snd0 -machine pcspk-audiodev=snd0 \
	-drive file=./bin/image.iso,format=raw,index=0,media=disk \
	-chardev stdio,id=char0,logfile=serial.log,signal=off \
	-serial chardev:char0

debug: iso
	qemu-system-$(ARCH) \
	-m 32M \
	-no-reboot \
	-s -S \
	-d guest_errors \
	-audiodev pa,id=snd0 -machine pcspk-audiodev=snd0 \
	-drive file=./bin/image.iso,format=raw,index=0,media=disk \
	-chardev stdio,id=char0,logfile=serial.log,signal=off \
	-serial chardev:char0 & \
	gdb -ex "target remote localhost:1234"

clean:
	$(RM) ./bin *.iso *.o