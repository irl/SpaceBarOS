SpaceBarOS
==========

A spacebar oriented lightweight operating system for the x86 platform.

See http://irl.unixcab.org/projects/sbos/ for more details. They may
be merged in here sometime soon.

Quick Start
-----------

To get SpaceBarOS running in qemu, you may first need to install some
dependancies.

* GNU make
* GCC
* nasm
* QEMU

On a Debian-based Linux system (Debian, Ubuntu, Linux Mint, ...) you can
install these with:

	sudo apt-get install build-essential nasm qemu
	
On Ubuntu 12.04, you will also need to install another package:
	
	sudo apt-get install qemu-system-i386
	
Then you'll need to clone the source code and build it:

	git clone git://github.com/irl/SpaceBarOS.git
	cd SpaceBarOS/
	make kernel.bin

To start SpaceBarOS in QEMU, then type:

	make run

Simulator
---------

A JavaScript based simulator of SpaceBarOS is available for those that
would like to have the experience of running it without having to set up
a VM or finding a PC to run it on. You can find this
[here](http://irl.unixcab.org/projects/sbos/sbos.html).

Experimental Linux Support
--------------------------

Under the linux/ folder, there are some files that allow for the
spacebar application to be compiled under Linux. They do not currently
work well at all and should be avoided. The aim is to make an ncurses
wrapper for the SBOS terminal functions.

If you do intend to try it out, make sure to install `libncurses-dev`.

	make linux
	./spacebar

Acknowlegements
---------------

Thanks to Andrew McManus for helping me test out SpaceBarOS and find any
problems that might affect Ubuntu users.

License
-------

	SpaceBarOS (C) Iain R. Learmonth <irl@sdf.org> 2011-2012.
	
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
