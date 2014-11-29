cmd_/root/lab4/myproc.ko := ld -r -m elf_i386 -T /usr/src/linux-headers-3.13.0-32-generic/scripts/module-common.lds --build-id  -o /root/lab4/myproc.ko /root/lab4/myproc.o /root/lab4/myproc.mod.o
