#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xe00b4984, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x945e4c08, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0xf82eacf7, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xe2cb65c5, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x99c316ce, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xb742fd7, __VMLINUX_SYMBOL_STR(simple_strtol) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "084AB453EA38B8B7B6F409C");
