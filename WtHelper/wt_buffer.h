#ifndef __WT_BUFFER_H_
#define __WT_BUFFER_H_

typedef void* wt_buffer_t;

wt_buffer_t wt_buffer_create(void);
int wt_buffer_enqueue(wt_buffer_t buffer, char value);
char wt_buffer_dequeue(wt_buffer_t buffer);
void wt_buffer_delete(wt_buffer_t buffer);


#endif