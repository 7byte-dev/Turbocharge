#
# compiles the static drivers into .o ELFs and archives them into libdrivers.a
#
CC=i386-elf-gcc
AR=i386-elf-ar

#
# Compile
#
$CC -ffreestanding -m32 -c -Ilibraries dummy.c -o dummy.o
$CC -ffreestanding -m32 -c -Ilibraries io.c -o io.o
$CC -ffreestanding -m32 -c -Ilibraries keyboard.c -o keyboard.o
$CC -ffreestanding -m32 -c -Ilibraries graphics.c -o graphics.o
$CC -ffreestanding -m32 -c -Ilibraries ide.c -o ide.o
$CC -ffreestanding -m32 -c -Ilibraries basic.c -o basic.o

#
# Archive
#
$AR rcs libdrivers.a dummy.o io.o keyboard.o graphics.o ide.o basic.o