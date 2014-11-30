cmd_/root/lab5/rwproc.ko := ld -r -m elf_i386 -T /usr/src/linux-headers-3.13.0-32-generic/scripts/module-common.lds --build-id  -o /root/lab5/rwproc.ko /root/lab5/rwproc.o /root/lab5/rwproc.mod.o
