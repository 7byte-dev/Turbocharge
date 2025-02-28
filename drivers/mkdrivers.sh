#
# compiles the static drivers into .o ELFs and archives them into libdrivers.a
#
CC=i386-elf-gcc
AR=i386-elf-ar

#
# Compile
#
$CC -ffreestanding -m32 -c -I../libraries dummy.c -o dummy.o
$CC -ffreestanding -m32 -c -I../libraries io.c -o io.o
$CC -ffreestanding -m32 -c -I../libraries keyboard.c -o keyboard.o

#
# Archive
#
$AR rcs libdrivers.a dummy.o io.o keyboard.o