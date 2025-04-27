BOOTLDR = bootloader
DRIVERS = drivers
KERNEL = kernel
LIBS = libraries
INTS = interrupts
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

$(BIN)/k.bin: $(BIN)/kenter.o $(BIN)/k.o $(BIN)/isr.o $(BIN)/idt.o $(BIN)/pic.o $(BIN)/isr_stubs.o $(BIN)/idt_flush.o $(BIN)/font.o $(DRIVERS)/libdrivers.a
	$(LD) -o $@ -T kernel.ld $^ $(LDFLAGS)

$(BIN)/k.o: $(KERNEL)/kernel.c $(LIBS)/basic.h $(LIBS)/drivers.h $(LIBS)/font.bmp.h $(LIBS)/memory.h
	$(CC) $(CCFLAGS) -o $@ $<

$(BIN)/kenter.o: $(KERNEL)/kenter.asm
	$(ASM) -f elf32 -o $@ $<

# interrupts for the kernel
$(BIN)/isr.o: $(INTS)/isr.c $(INTS)/isr.h
	$(CC) $(CCFLAGS) -o $@ $<
$(BIN)/idt.o: $(INTS)/idt.c $(INTS)/idt.h
	$(CC) $(CCFLAGS) -o $@ $<
$(BIN)/pic.o: $(INTS)/pic.c $(INTS)/pic.h
	$(CC) $(CCFLAGS) -o $@ $<
$(BIN)/idt_flush.o: $(INTS)/idt_flush.s
	$(ASM) -f elf32 -o $@ $<
$(BIN)/isr_stubs.o: $(INTS)/isr_stubs.s
	$(ASM) -f elf32 -o $@ $<

$(BIN)/font.o: $(LIBS)/font.c $(LIBS)/font.bmp.h
	$(CC) $(CCFLAGS) -o $@ $<

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
			rm -v $(DRIVERS)/*.o $(DRIVERS)/*.a;	\
		else	\
			echo "Nothing to clean!";	\
		fi	\
	}