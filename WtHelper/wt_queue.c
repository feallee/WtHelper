#include <stdlib.h>
#include <assert.h>
#include "wt_queue.h"

struct node {
	void* data;
	unsigned short length;
	struct node* next;
};

typedef struct {
	struct node* head;
	struct node* tail;
}container;

static int isempty(container* c)
{
	assert(c);
	return c->head == NULL;
}

wt_queue_t wt_queue_create(void)
{
	container* r;
	r = malloc(sizeof(container));
	if (r)
	{
		r->head = NULL;
		r->tail = NULL;
	}
	return r;
}


int wt_queue_enqueue(wt_queue_t queue, void* data, unsigned short length)
{
	int r;
	struct node* n;
	assert(queue && data && length);
	n = (struct node*)malloc(sizeof(struct node));
	if (n)
	{
		container* c = queue;
		n->data = data;
		n->length = length;
		n->next = NULL;
		if (isempty(queue))
		{
			c->head = n;
			c->tail = n;
		}
		else
		{
			c->tail->next = n;
			c->tail = n;
		}
		r = 1;
	}
	else
	{
		r = 0;
	}
	return r;
}

unsigned short wt_queue_dequeue(wt_queue_t queue, void* data)
{
	unsigned short r;
	assert(queue && data);

	if (isempty(queue))
	{
		r = 0;
	}
	else
	{
		container* c = queue;
		struct node* n = c->head;
		data = n->data;
		r = n->length;
		c->head = n->next;
		free(n);
		if (c->head)
		{
			c->tail = NULL;
		}
	}
	return r;
}

unsigned short wt_queue_peek(wt_queue_t queue, void* data)
{
	unsigned short r;
	assert(queue && data);
	if (isempty(queue))
	{
		r = 0;
	}
	else
	{
		container* c = queue;
		r = c->head->length;
		data = c->head->data;
	}
	return r;
}

unsigned short wt_queue_count(wt_queue_t queue)
{
	unsigned short r = 0;
	assert(queue);
	container* c = queue;
	struct node* curr = c->head;
	while (curr != NULL) {
		r++;
		curr = curr->next;
	}
	return r;
}

void wt_queue_delete(wt_queue_t queue)
{
	assert(queue);
	container* c = queue;
	struct node  n;
	while (!isempty(c))
	{
		wt_queue_dequeue(c,&n);
	}
	free(queue);
}
