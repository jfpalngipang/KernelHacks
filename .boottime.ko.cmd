cmd_/root/lab3/boottime.ko := ld -r -m elf_i386 -T /usr/src/linux-headers-3.13.0-32-generic/scripts/module-common.lds --build-id  -o /root/lab3/boottime.ko /root/lab3/boottime.o /root/lab3/boottime.mod.o