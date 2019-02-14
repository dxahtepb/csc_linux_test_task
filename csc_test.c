#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched/signal.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Andrey Chausov");
MODULE_DESCRIPTION("Counts processes in the system at initialization time.");
MODULE_VERSION("0.1337");

static int __init my_init(void)
{
	struct task_struct *task;
	unsigned int process_counter;

	printk("Module loaded\n");

	process_counter = 0;
	for_each_process(task)
	{
		process_counter += 1;
	}

	printk("Number of processes in the system: %u\n", process_counter);

	return 0;
}

static void __exit my_exit(void)
{
	printk("Module removed\n");
}

module_init(my_init);
module_exit(my_exit);
