#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <asm/io.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Franz Palngipang<franz.palngipang@gmail.com>");
MODULE_DESCRIPTION("coe 135 me11");

void __iomem *serialptr;
//callback function for writing:
int write_proc(struct file *file_ptr, const char *buf, size_t count, loff_t *offp)
{
	char *msg;
	long num;
	
	msg=kmalloc(GFP_KERNEL,10*sizeof(char));
	
	copy_from_user(msg, buf, count);
	
	num = simple_strtol(msg, NULL, 16);  //convert to integer
	iowrite8(num, serialptr);	
	
	kfree(msg);
	return count;
}
struct file_operations proc_fops = {
//	read: read_proc,
	write: write_proc
};

static int __init serial_init(void)
{
	proc_create("linereg",0,NULL,&proc_fops);
	serialptr = ioport_map(0x3f8, 1);
	return 0;
}
static void __exit serial_exit(void)
{
	ioport_unmap(serialptr);
	remove_proc_entry("linereg", NULL);
	printk(KERN_INFO "Cleaning up lab11 module...\n");
}

module_init(serial_init);
module_exit(serial_exit);
