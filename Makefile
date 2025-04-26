BOOTLDR = bootloader
DRIVERS = drivers
KERNEL = kernel
LIBS = libraries
BIN = bin

CC = i386-elf-gcc
LD = i386-elf-ld
ASM = nasm

CCFLAGS = -ffreestanding -m32 -g -c -Ilibraries -Idrivers
LDFLAGS = --oformat binary

.PHONY: all ready bootloader drivers kernel

#
# all
#
all: ready bootloader drivers kernel
	cat $(BIN)/boot.bin $(BIN)/k.bin > $(BIN)/tcos.img

#
# bootloader
#
bootloader: $(BIN)/boot.bin

$(BIN)/boot.bin: $(BOOTLDR)/boot.asm
	$(ASM) -f bin -o $@ $<

#
# drivers
#
drivers: $(DRIVERS)/libdrivers.a

$(DRIVERS)/libdrivers.a: $(DRIVERS)/basic.c $(DRIVERS)/graphics.c $(DRIVERS)/ide.c $(DRIVERS)/io.c $(DRIVERS)/keyboard.c $(DRIVERS)/mkdrivers.sh $(LIBS)/basic.h $(DRIVERS)/graphics.h $(DRIVERS)/ide.h $(DRIVERS)/io.h $(DRIVERS)/keyboard.h
	cd $(DRIVERS)/ && sh mkdrivers.sh

#
# kernel
#
kernel: $(BIN)/k.bin

$(BIN)/k.bin: $(BIN)/kenter.o $(BIN)/k.o $(DRIVERS)/libdrivers.a
	$(LD) -o $@ -T kernel.ld $^ $(LDFLAGS)

$(BIN)/k.o: $(KERNEL)/kernel.c $(LIBS)/basic.h $(LIBS)/drivers.h $(LIBS)/font.bmp.h $(LIBS)/memory.h
	$(CC) $(CCFLAGS) -o $@ $<

$(BIN)/kenter.o: $(KERNEL)/kenter.asm
	$(ASM) -f elf32 -o $@ $<

#
# ready
#
ready:
	mkdir -p $(BIN)/

#
# clean
#
clean:
	@{	\
		if [ -d $(BIN)/ ]; then	\
			rm -rfv $(BIN)/;	\
		else	\
			echo "Nothing to clean!";	\
		fi	\
	}