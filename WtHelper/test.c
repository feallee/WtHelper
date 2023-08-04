#include <stdio.h>
#include "wt_slink.h"
static void slist_test(void)
{
	struct device
	{
		wt_slist_t slist;//此字段必须在第一个位置
		char id;
	}root = { {NULL},0 }, dev1 = { {NULL},1 }, dev2 = { {NULL},2 }, dev3 = { {NULL},3 };
	wt_slist_t* curr;
	wt_slist_setnext((wt_slist_t*)&root, NULL);
	wt_slist_append((wt_slist_t*)&root, (wt_slist_t*)&dev1);
	wt_slist_append((wt_slist_t*)&root, (wt_slist_t*)&dev2);
	wt_slist_insert((wt_slist_t*)&dev1, (wt_slist_t*)&dev3);
	printf("length:%d\n", wt_slist_count((wt_slist_t*)&root));
	curr = (wt_slist_t*)&root;
	printf("slist:%d,", ((struct device*)curr)->id);
	curr = curr->next;
	printf("%d,", ((struct device*)curr)->id);
	curr = curr->next;
	printf("%d,", ((struct device*)curr)->id);
	curr = curr->next;
	printf("%d\n", ((struct device*)curr)->id);

	wt_slist_remove((wt_slist_t*)&root, (wt_slist_t*)&dev1);
	printf("length:%d\n", wt_slist_count((wt_slist_t*)&root));
	printf("first id:%d\n", ((struct device*)wt_slist_first((wt_slist_t*)&root))->id);
	printf("last id:%d\n", ((struct device*)wt_slist_last((wt_slist_t*)&root))->id);
	printf("root is empty:%d\n", wt_slist_isempty((wt_slist_t*)&root));
	printf("dev3 is empty:%d\n", wt_slist_isempty((wt_slist_t*)&dev3));
}

int main(void)
{
	slist_test();
	return 0;
}