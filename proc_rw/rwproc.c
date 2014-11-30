#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Franz Palngipang<franz.palngipang@gmail.com>");
MODULE_DESCRIPTION("coe 135 me5");

char uspace_buf[128]; 
int len, temp;		
long test, num;
char info[128];		//string to be printed in userspace

//recursive function for computing factorial
long get_factorial(int x)
{
	if(x == 0)
		return 1;
	else
		return(x * get_factorial(x-1));
}

//callback function for reading:
int read_proc(struct file *file_ptr, char *buf, size_t count, loff_t *offp)
{
	info[0] = '\0';		//clear string
	
	if(count>temp)
	{
		count=temp;
	}
	temp=temp-count;
	sprintf(info, "%lu\n", test);	
	copy_to_user(buf, info, count);
	if(count==0)
		temp=len;
   
	return count;
}
//callback function for writing:
int write_proc(struct file *file_ptr, const char *buf, size_t count, loff_t *offp)
{
	//init global variables
	len = 0;
	temp = 0;
	num = 0;
	
	copy_from_user(uspace_buf, buf, count);
	len = count+5;
	temp = len;	
	
	num = simple_strtol(buf, NULL, 10);  //convert to integer
	test = get_factorial(num);
	
	return count;
}
struct file_operations proc_fops = {
	read: read_proc,
	write: write_proc
};

static int __init create_myprocfs(void)
{
	proc_create("myprocfs",0,NULL,&proc_fops);
	return 0;
}
static void __exit exit_myprocfs(void)
{
	printk(KERN_INFO "Cleaning up lab5 module...\n");
	remove_proc_entry("myprocfs", NULL);
}

module_init(create_myprocfs);
module_exit(exit_myprocfs);
