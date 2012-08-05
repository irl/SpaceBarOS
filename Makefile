kernel.bin: loader.o kernel.o term.o kbd.o io.o string.o
	ld -T linker.ld -o kernel.bin loader.o kernel.o term.o kbd.o io.o string.o
loader.o:
	nasm -f elf -o loader.o loader.s
kernel.o:
	gcc -o kernel.o -c kernel.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs
term.o:
	gcc -o term.o -c term.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs
io.o:
	gcc -o io.o -c io.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs
kbd.o:
	gcc -o kbd.o -c kbd.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs
string.o:
	gcc -o string.o -c string.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs
clean:
	rm -f loader.o kernel.o term.o io.o kbd.o string.o kernel.bin
run:
	qemu -kernel kernel.bin
grub-floppy: kernel.bin
	cat grub/stage1 grub/stage2 grub/pad kernel.bin > sbos.img
