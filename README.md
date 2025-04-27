# Turbocharge
## A rage-driven, Terry Davis inspired x86 operating system, made with love and sleep-deprivation

When I was 12 or 13, I was fresh out of a few C courses. I wanted to make something cool with C but guess what, segfaults. Segfaults everywhere. One day at 13 years-old I got so mad, I scrapped all my projects, opened up YouTube, searched "how to make an os" and watched the tutorials. And, well, here I am, 14 years-old with a functional kernel.

### What is Turbocharge OS (TCOS)?
Turbocharge, or TCOS for short, is an experimental x86 kernel-only graphical operating system. TCOS is still in it's early development stages so it's still pretty boring lol.

### What is TCOS capable of?
TCOS has:
- A working one-command-only shell with a working ECHO function
- 320x200 8-bit colors graphic mode
- A paged 256KiB memory (WIP, gonna change soon)
- A working custom hard-coded font (I worked so hard on it T-T)

What I plan on implementing to TCOS:
- FrostbyteFS, a FAT *inspired* filesystem (I wanna keep it basic ok?)
- A working stdin and stdout
- Dynamic drivers
- and more...!

### How do I use it?
To use TCOS, you have two options (three if you're feeling brave):
#### Option 1: Build from source (recommended)
**Prequisites:**
- A linux system (or a subsystem)
- `git`
- `i386-elf` cross-compiler and binutils
- `qemu-system-x86_64` or other virtualization software
- `make`

First clone the repository using git: ```git clone https://github.com/7byte-dev/Turbocharge.git --depth 1```
After that, you will need to build the source with `make`: ```make all```
Now you're good to go! You can virtualize TCOS with the generated `run.sh` script! ```sh run.sh```

#### Option 2: Download the binary file directly (less control, easier)
You can download the binary release from [here](https://github.com/7byte-dev/Turbocharge/releases/tag/frost-flavor) and then use any virtualization software (like `qemu`) to virtualize TCOS.