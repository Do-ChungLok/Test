#include <linux/list.h> 
#include <linux/kernel.h> 	/* 'KERN_INFO', 'printk()' 사용 */
#include <linux/module.h> 	/* 'Kernel Moudle' 사용 */
#include <linux/types.h>	/* 'list_head' 사용 */

typedef struct Service_type{
	char *service_type;
	struct list_head list;
}Node;

/*
struct list_head{
	struct list_head *next, *prev;
};
*/

int init_list_test(void)
{
	LIST_HEAD(list);
			
	Node node1;
	Node node2;
	Node node3;
	
	Node *now;
	
	printk("List Module Insert\n");
	
	node1.service_type="display";
	node2.service_type="getkeyboard";
	node3.service_type="start_process";	
	
	INIT_LIST_HEAD(&list);
	
	list_add(&node1.list,&list);
	list_add(&node2.list,&list);
	list_add(&node3.list,&list);	
	
	list_for_each_entry(now,&list,list)
	{
		printk("service_type = %s\n", now->service_type);
	}
	
	return 0;
}

void exit_list_test(void)
{
	printk("List Module Remove\n");
}

module_init(init_list_test);
module_exit(exit_list_test);
MODULE_LICENSE("GPL");

















