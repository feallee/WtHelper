#include <stdlib.h>
#include <assert.h>
#include "wt_slist.h"
#include "wt_queue.h"

typedef struct Node
{
	wt_slist_t list;
	size_t data;
} Node;

wt_queue_t wt_queue_create(void)
{
	wt_queue_t q = malloc(sizeof(wt_slist_t));
	if (q)
	{
		wt_slist_initialize(q);
	}
	return q;
}

int wt_queue_enqueue(wt_queue_t queue, size_t data)
{
	int r;
	Node* n;
	assert(queue);
	n = malloc(sizeof(Node));
	if (n)
	{
		n->data = data;
		wt_slist_append(queue, (wt_slist_t*)n);
		r = 1;
	}
	else
	{
		r = 0;
	}
	return r;
}

int wt_queue_dequeue(wt_queue_t queue, size_t* data)
{
	int r;
	wt_slist_t* n;
	assert(queue && data);
	n = wt_slist_first(queue);
	if (n)
	{
		*data = ((Node*)n)->data;
		wt_slist_remove(queue, n);
		free(n);
		r = 1;
	}
	else
	{
		r = 0;
	}
	return r;
}

int wt_queue_peek(wt_queue_t queue, size_t* data)
{
	int r;
	wt_slist_t* n;
	assert(queue && data);
	n = wt_slist_first(queue);
	if (n)
	{
		*data = ((Node*)n)->data;
		r = 1;
	}
	else
	{
		r = 0;
	}
	return r;
}

void wt_queue_delete(wt_queue_t queue)
{
	wt_slist_t* q, * n;
	assert(queue);
	q = queue;
	wt_slist_for_each(n, q);
	{
		free(n);
	}
	free(queue);
}
