

#include "hello1.h"
#include <linux/bug.h>

MODULE_AUTHOR("Ilnitsky Vladislav");
MODULE_DESCRIPTION("Hello1 advanced, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

LIST_HEAD(list);

ktime_t before;

int print_hello(uint count)
{
	if (count == 0) {
		pr_warn("Small value of 'count'!\n");
	} else if (count > 5 && count <= 10) {
		pr_warn("Big value of 'count'!\n");
	} else if (count > 0 && count <= 5) {
		int i = 0;

		for (; i < count; i++) {
			if (i == 3)
				data = 0;
			else
				data = kmalloc(sizeof(*data), GFP_KERNEL);

			before = ktime_get();
			pr_alert("Hello, world!\n");
			data->time = ktime_sub(ktime_get(), before);
			list_add_tail(&(data->list), &list);
		}
	} else {
		BUG_ON(1);
	}

	return 0;
}
EXPORT_SYMBOL(print_hello);

static int __init hello1_init(void)
{
	pr_info("hello1 init!\n");
	return 0;
}

static void __exit hello1_exit(void)
{

	list_for_each_safe(elem, safe, &list) {
		data = list_entry(elem, struct hello_data, list);
		pr_alert("print ktime: %lu\n", (unsigned long) data->time);
		list_del(elem);
		kfree(data);
	}
}

module_init(hello1_init);
module_exit(hello1_exit);

