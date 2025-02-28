BOOTLDR=bootloader
KERNEL=kernel
BIN=bin
DRIVERS=drivers

ASM=nasm
CC=i386-elf-gcc
LD=i386-elf-ld

.PHONY: all bootloader drivers kernel clean ready

#
# All
#
all: ready bootloader drivers kernel
	cat $(BIN)/boot.bin $(BIN)/k.bin > $(BIN)/OS.bin

#
# Bootloader
#
bootloader: $(BIN)/boot.bin

$(BIN)/boot.bin: $(BOOTLDR)/boot.asm
	$(ASM) -f bin -o $(BIN)/boot.bin $(BOOTLDR)/boot.asm

#
# Drivers
#
drivers: $(DRIVERS)/*
	cd $(DRIVERS) && sh mkdrivers.sh

#
# Kernel
#
kernel: $(BIN)/k.bin

$(BIN)/k.bin: $(BIN)/kenter.o $(BIN)/kmain.o
	$(LD) -o $(BIN)/k.bin -T kernel.ld $(BIN)/kenter.o $(BIN)/kmain.o $(DRIVERS)/libdrivers.a --oformat binary
	truncate -s 16K $(BIN)/k.bin

$(BIN)/kenter.o: $(KERNEL)/kenter.asm
	$(ASM) -f elf -o $(BIN)/kenter.o $(KERNEL)/kenter.asm

$(BIN)/kmain.o: $(KERNEL)/kernel.c
	$(CC) -ffreestanding -m32 -g -c -Ilibraries $(KERNEL)/kernel.c -o $(BIN)/kmain.o

#
# Clean
clean:
	rm -r $(BIN)/
	rm $(DRIVERS)/*.o
	rm $(DRIVERS)/*.a

#
# Ready
#
ready:
	mkdir -p $(BIN)/
	echo "qemu-system-x86_64 -drive format=raw,index=0,if=ide,file=$(BIN)/OS.bin, -m 128M" > ./run.sh
	chmod +x ./run.sh