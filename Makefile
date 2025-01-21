# source and binary
SRC=src
BIN=bin

# files
BOOT=$(SRC)/bootloader/boot.asm
KERNDIR=$(SRC)/kernel

# programs
ASM=nasm
GCC=i386-elf-gcc
LD=i386-elf-ld

# phony
.PHONY: all bootloader kernel ready clean

#
# All
#
all: clean ready bootloader kernel
	cat $(BIN)/bootloader.bin $(BIN)/kernel.bin $(BIN)/kz.bin > $(BIN)/Turbocharge.img

#
# Bootloader
#
bootloader: $(BIN)/bootloader.bin

$(BIN)/bootloader.bin: $(BOOT)
	$(ASM) -f bin $(BOOT) -o $(BIN)/bootloader.bin

#
# Kernel
#
kernel: $(BIN)/Quasar32.bin

$(BIN)/Quasar32.bin: $(KERNDIR)/*
	$(GCC) -ffreestanding -m32 -g -c $(KERNDIR)/Quasar32.c -o $(BIN)/Q32Main.o
	$(ASM) -f elf -o $(BIN)/kenter.o $(KERNDIR)/kern_enter.asm
	$(ASM) -f bin -o $(BIN)/kz.bin $(KERNDIR)/kern_z.asm
	$(LD) -T linker.ld "$(BIN)/kenter.o" "$(BIN)/Q32Main.o" -o "$(BIN)/kernel.bin" --oformat binary

#
# Ready
#
ready:
	mkdir -p bin
	chmod +x ./run.sh

#
# Clean
#
clean:
	rm -frv bin/