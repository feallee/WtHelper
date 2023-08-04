#ifndef __WT_QUEUE_H_
#define __WT_QUEUE_H_

typedef void* wt_queue_t;

wt_queue_t wt_queue_create(void);
int wt_queue_enqueue(wt_queue_t queue,const void* value);
void* wt_queue_dequeue(wt_queue_t queue);
void wt_queue_delete(wt_queue_t queue);


#endif