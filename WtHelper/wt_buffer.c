#include "wt_buffer.h"

void wt_buffer_init(wt_buffer_type* buffer, uint8_t* pool, int32_t capacity)
{
	buffer->capacity = capacity;
	buffer->pool = pool;
	buffer->read_mirror = buffer->read_index = buffer->write_mirror = buffer->write_index = 0;
}

int32_t wt_buffer_write_byte(wt_buffer_type* buffer, const uint8_t segment)
{
	if (buffer->write_index == buffer->read_index && buffer->write_mirror != buffer->read_mirror)
	{
		return 0;
	}
	else
	{
		buffer->pool[buffer->write_index] = segment;
		if (buffer->write_index == buffer->capacity - 1)
		{
			buffer->write_index = 0;
			buffer->write_mirror = ~buffer->write_mirror;
		}
		else
		{
			buffer->write_index++;
		}
		return 1;
	}
}

int32_t wt_buffer_read_byte(wt_buffer_type* buffer, uint8_t* segment)
{
	if (buffer->write_index == buffer->read_index && buffer->write_mirror == buffer->read_mirror)
	{
		return 0;
	}
	else
	{
		*segment = buffer->pool[buffer->read_index];
		if (buffer->read_index == buffer->capacity - 1)
		{
			buffer->read_index = 0;
			buffer->read_mirror = ~buffer->read_mirror;
		}
		else
		{
			buffer->read_index++;
		}
		return 1;
	}
}
