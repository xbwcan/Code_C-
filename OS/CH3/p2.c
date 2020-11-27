#include <linux/sched.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>
/* This function is called when the module is loaded. */

    
void dfs(struct task_struct *cur) 
{
    if (cur == NULL)
        return;
    struct task_struct *task;
    struct list_head *list;
    
    printk(KERN_INFO "Name: %s, State: %ld, Pid: %d\n", cur->comm, cur->state, cur->pid);
    list_for_each(list, &cur->children) {
        task = list_entry(list, struct task_struct, sibling);
        dfs(task);
    }
}
int Init(void)
{
    printk(KERN_INFO "Loading Module \n");
    dfs(&init_task);
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
