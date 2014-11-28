#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/time.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Franz Palngipang<franz.palngipang@gmail.com>");
MODULE_DESCRIPTION("coe 135 me3");

static int __init kern_uptime_init(void)
{
	struct timespec ts_boot, ts_now;
	getboottime(&ts_boot);		//time of boot
	getnstimeofday(&ts_now);	//time now
	long ts_diff;	//difference bet. time of boot and time now
	
	//Debug by printing...
	//printk(KERN_INFO "BOOT TIME: %lu\n", ts_boot.tv_sec);
	//printk(KERN_INFO "TIME NOW: %lu\n", ts_now.tv_sec);
	ts_diff = ts_now.tv_sec - ts_boot.tv_sec;
	//printk(KERN_INFO "DIFFERENCE: %lu\n", ts_diff);
	
	long hours, minutes, seconds;
	//formatting HH:MM:SS
	hours = ts_diff/3600;
	minutes = (ts_diff%3600)/60;
	seconds = (ts_diff%3600)%60;
	printk(KERN_INFO "UPTIME: %02lu:%02lu:%02lu\n",hours, minutes, seconds);
	return 0;
}
static void __exit kern_uptime_cleanup(void)
{
	printk(KERN_INFO "Cleaning up lab3 module...");
}

module_init(kern_uptime_init);
module_exit(kern_uptime_cleanup);
