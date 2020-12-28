/* SPDX-License-Identifier: GPL-3.0-only */
#ifndef HELLO1_H
#define HELLO1_H
#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/ktime.h>
#include <linux/list.h>
#include <linux/slab.h>

struct hello_data {
	ktime_t time;
	struct list_head list;
};

struct list_head *elem, *safe;
struct hello_data *data;

int print_hello(uint count);

#endif
