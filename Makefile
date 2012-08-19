.PHONY: clean run grub-floppy linux

linux: build build/spacebar.o
	gcc -ggdb -lncurses -o spacebar linux/* spacebar.c
kernel.bin: build/loader.o build/term.o build/kbd.o build/io.o build/string.o build/spacebar.o build/sbos.o
	ld -melf_i386 -T sbos/linker.ld -o kernel.bin build/loader.o build/term.o build/kbd.o build/io.o build/string.o build/sbos.o build/spacebar.o
build:
	mkdir build
build/loader.o: build
	nasm -f elf -o build/loader.o sbos/loader.s
build/sbos.o: build
	gcc -m32 -o build/sbos.o -c sbos/sbos.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs
build/term.o: build
	gcc -m32 -o build/term.o -c sbos/term.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs
build/io.o: build
	gcc -m32 -o build/io.o -c sbos/io.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs
build/kbd.o: build
	gcc -m32 -o build/kbd.o -c sbos/kbd.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs
build/string.o: build
	gcc -m32 -o build/string.o -c sbos/string.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs
build/spacebar.o:
	gcc -m32 -o build/spacebar.o -c spacebar.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs
clean:
	-rm -rf build/
	-rm -f kernel.bin
	-rm -f spacebar
run: kernel.bin
	qemu -kernel kernel.bin
grub-floppy: kernel.bin
	cat grub/stage1 grub/stage2 grub/pad kernel.bin > sbos.img
