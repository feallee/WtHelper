#ifndef __WT_BUFFER_H_
#define __WT_BUFFER_H_

typedef void* wt_buffer_t;

typedef enum
{
	WT_BUFFER_EMPTY,
	WT_BUFFER_FULL,
	WT_BUFFER_HALFFULL,
}wt_buffer_state;

wt_buffer_t wt_buffer_create(unsigned short  capacity);
void wt_buffer_delete(wt_buffer_t buffer);

wt_buffer_state wt_buffer_getsatate(wt_buffer_t buffer);

int wt_buffer_putchar(wt_buffer_t buffer, unsigned char data);
int wt_buffer_getchar(wt_buffer_t buffer, unsigned char* data);

void wt_buffer_clear(wt_buffer_t buffer);


#endif