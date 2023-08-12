#include <stdlib.h>
#include <assert.h>
#include "wt_buffer.h"

typedef struct
{
	unsigned char* buffer;
	unsigned short read_mirror : 1;
	unsigned short read_index : 15;
	unsigned short write_mirror : 1;
	unsigned short write_index : 15;
	unsigned short capacity;
}Buffer;

wt_buffer_t wt_buffer_create(unsigned short capacity)
{
	Buffer* r;
	assert(capacity > 0 && capacity <= 32768);
	r = malloc(sizeof(Buffer));
	if (r)
	{
		r->buffer = malloc(capacity);
		if (r->buffer)
		{
			r->read_index = 0;
			r->read_mirror = 0;
			r->write_index = 0;
			r->write_mirror = 0;
			r->capacity = capacity;
		}
		else
		{
			free(r);
			r = NULL;
		}
	}
	return r;
}

void wt_buffer_delete(wt_buffer_t buffer)
{
	Buffer* b;
	assert(buffer);
	b = buffer;
	free(b->buffer);
	free(b);
}

wt_buffer_state wt_buffer_getsatate(wt_buffer_t buffer)
{
	wt_buffer_state r;
	Buffer* b;
	assert(buffer);
	b = buffer;
	if (b->read_index == b->write_index)
	{
		if (b->read_mirror == b->write_mirror)
		{
			r = WT_BUFFER_EMPTY;
		}
		else
		{
			r = WT_BUFFER_FULL;
		}
	}
	else
	{
		r = WT_BUFFER_HALFFULL;
	}
	return r;
}

int wt_buffer_putchar(wt_buffer_t buffer, unsigned char data)
{
	int r;
	Buffer* b;
	assert(buffer);
	b = buffer;
	if (wt_buffer_getsatate(buffer) == WT_BUFFER_FULL)
	{
		r = 0;
	}
	else
	{
		b->buffer[b->write_index] = data;
		if (b->write_index == b->capacity - 1)
		{
			b->write_mirror = ~b->write_mirror;
			b->write_index = 0;
		}
		else
		{
			b->write_index++;
		}
		r = 1;
	}
	return r;
}

int wt_buffer_getchar(wt_buffer_t buffer, unsigned char* data)
{
	int r;
	Buffer* b;
	assert(buffer);
	b = buffer;
	if (wt_buffer_getsatate(buffer) == WT_BUFFER_EMPTY)
	{
		r = 0;
	}
	else
	{
		*data = b->buffer[b->read_index];
		if (b->read_index == b->capacity - 1)
		{
			b->read_mirror = ~b->read_mirror;
			b->read_index = 0;
		}
		else
		{
			b->read_index++;
		}
		r = 1;
	}
	return r;
}

void wt_buffer_clear(wt_buffer_t buffer)
{
	Buffer* b;
	assert(buffer);
	b = buffer;
	b->read_mirror = 0;
	b->read_index = 0;
	b->write_mirror = 0;
	b->write_index = 0;
}