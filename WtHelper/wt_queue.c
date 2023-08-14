#include <stdlib.h>
#include <assert.h>
#include "wt_queue.h"

typedef struct Node
{
	size_t data;
	struct Node* next;
} Node;

typedef struct
{
	Node* front;
	Node* rear;
} Queue;

wt_queue_t wt_queue_create(void)
{
	Queue* q = malloc(sizeof(Queue));
	if (q)
	{
		q->front = q->rear = NULL;
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
		Queue* q = queue;
		n->data = data;
		n->next = NULL;		
		if (q->front)
		{
			q->rear->next = n;
			q->rear = n;
		}
		else
		{
			q->front = n;
			q->rear = n;
		}
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
	assert(queue && data);
	Queue* q = queue;
	if (q->front)
	{
		Node* n = q->front;
		*data = n->data;
		q->front = n->next;
		free(n);
		if (q->front == NULL)
		{
			q->rear = NULL;
		}
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
	assert(queue && data);
	Queue* q = queue;
	if (q->front)
	{
		*data = q->front->data;
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
	Queue* q;
	Node* n;
	assert(queue);
	q = queue;
	while (q->front)
	{
		n = q->front;
		q->front = n->next;
		free(n);
	}
	free(queue);
}
