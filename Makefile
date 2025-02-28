SRC=src
BIN=bin

ASM=nasm
CC=i386-elf-gcc
LD=i386-elf-ld

.PHONY: all bootloader kernel clean ready

#
# All
#
all: ready bootloader kernel
	cat $(BIN)/boot.bin $(BIN)/k.bin > $(BIN)/OS.bin

#
# Bootloader
#
bootloader: $(BIN)/boot.bin

$(BIN)/boot.bin: $(SRC)/boot.asm
	$(ASM) -f bin -o $(BIN)/boot.bin $(SRC)/boot.asm

#
# Kernel
#
kernel: $(BIN)/k.bin

$(BIN)/k.bin: $(BIN)/kenter.o $(BIN)/kmain.o
	$(LD) -o $(BIN)/k.bin -Ttext 0x1000 $(BIN)/kenter.o $(BIN)/kmain.o --oformat binary
	truncate -s 16K $(BIN)/k.bin

$(BIN)/kenter.o: $(SRC)/kernel/kenter.asm
	$(ASM) -f elf -o $(BIN)/kenter.o $(SRC)/kernel/kenter.asm

$(BIN)/kmain.o: $(SRC)/kernel/kernel.c
	$(CC) -ffreestanding -m32 -g -c $(SRC)/kernel/kernel.c -o $(BIN)/kmain.o

#
# Clean
clean:
	rm -r $(BIN)/

#
# Ready
#
ready:
	mkdir -p $(BIN)/
	echo "qemu-system-x86_64 -drive format=raw,index=0,if=ide,file=$(BIN)/OS.bin, -m 128M" > ./run.sh
	chmod +x ./run.sh