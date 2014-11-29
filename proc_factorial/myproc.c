#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <linux/sched.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Franz Palngipang<franz.palngipang@gmail.com>");
MODULE_DESCRIPTION("coe 135 me4");

char *msg;

//recursive function for computing factorial
long get_factorial(int x)
{
	if(x == 0)
		return 1;
	else
		return(x * get_factorial(x-1));
}

//callback function for writing:
int write_proc(struct file *file_ptr, const char *buf, size_t count, loff_t *offp)
{
//	char *msg;
	long num;
	long test;
	
	//msg=kmalloc(GFP_KERNEL,10*sizeof(char));
	
	copy_from_user(msg, buf, count);
	
	num = simple_strtol(msg, NULL, 10);  //convert to integer
	test = get_factorial(num);
	printk(KERN_INFO "%lu\n", test);
	
	return count;
}
//callback function for reading:
int read_proc(struct file *file_ptr, char *buf, size_t count, loff_t *offp)
{
	copy_to_user(buf,msg,count);
	return 0;
}
struct file_operations proc_fops = {
	read: read_proc,
	write: write_proc
};

static int __init create_myprocfs(void)
{
	proc_create("myprocfs",0,NULL,&proc_fops);
	msg=kmalloc(GFP_KERNEL,10*sizeof(char));
	return 0;
}
static void __exit exit_myprocfs(void)
{
	printk(KERN_INFO "Cleaning up lab4 module...\n");
	remove_proc_entry("myprocfs", NULL);
}

module_init(create_myprocfs);
module_exit(exit_myprocfs);
