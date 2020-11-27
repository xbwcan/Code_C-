#include <linux/sched.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>
/* This function is called when the module is loaded. */
struct task_struct *task;
int Init(void)
{
    printk(KERN_INFO "Loading Module \n");
    for_each_process(task) {
        printk(KERN_INFO "Name: %s, State: %ld, Pid: %d\n", task->comm, task->state, task->pid);
    }
    return 0;
}
/* This function is called when the module is removed. */
void Exit(void)
{
    printk(KERN_INFO "Removing Module \n");
}
/* Macros for registering module entry and exit points. */
module_init(Init);
module_exit(Exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");