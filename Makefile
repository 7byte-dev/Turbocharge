SRC=src
BIN=bin

ASM=nasm
CC=i386-elf-gcc
LD=i386-elf-ld

.PHONY: all bootloader kernel clean ready

#
# All
#
all: bootloader kernel
	cat $(BIN)/boot.bin $(BIN)/k.bin > $(BIN)/TCOS.BIN

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

$(BIN)/k.bin: $(BIN)/Q32.o $(BIN)/kenter.o
	$(LD) -T kernel.ld -o $(BIN)/k.bin
	truncate -s 16K $(BIN)/k.bin

$(BIN)/Q32.o: $(SRC)/kernel/Quasar32.c
	$(CC) -ffreestanding -m32 -g -c $(SRC)/kernel/Quasar32.c -o $(BIN)/Q32.o

$(BIN)/kenter.o: $(SRC)/kernel/kenter.asm
	$(ASM) -f elf -o $(BIN)/kenter.o $(SRC)/kernel/kenter.asm

#
# Clean
#
clean:
	rm -frv $(BIN)

#
# Ready
#
ready:
	mkdir -p $(BIN)