// SPDX-License-Identifier: GPL-2.0


#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static char *whom = "MAI";
module_param(whom, charp, 0644);
MODULE_PARM_DESC(whom, "The one we say hello to");

static char *from = "425";
module_param(from, charp, 0644);
MODULE_PARM_DESC(from, "The one who says hello");

static int number = 1;
module_param(number, int, 0644);
MODULE_PARM_DESC(number, "Number of greetings");

static int __init hello_init(void)
{
	int i;

	for (i = 0; i < number; ++i)
		pr_alert("Hello, %s from %s (greeting %d)\n", whom, from, i);
	return 0;
}

static void __exit hello_exit(void)
{
	pr_alert("Goodbye, %s\n", whom);
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Greeting module");
MODULE_AUTHOR("Chernomorets M");