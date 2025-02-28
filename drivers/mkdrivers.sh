#
# compiles the static drivers into .o ELFs and archives them into libdrivers.a
#
CC=i386-elf-gcc
AR=i386-elf-ar

#
# Compile
#
$CC -ffreestanding -m32 -c test.c -o test.o

#
# Archive
#
$AR rcs libdrivers.a test.o