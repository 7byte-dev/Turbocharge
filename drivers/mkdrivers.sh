#
# compiles the static drivers into .o ELFs and archives them into libdrivers.a
#
CC=i386-elf-gcc
AR=i386-elf-ar

#
# Compile
#
$CC -ffreestanding -m32 -c dummy.c -o dummy.o

#
# Archive
#
$AR rcs libdrivers.a dummy.o