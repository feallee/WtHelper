#include "wt_converter.h"

uint32_t wt_converter_scanformat(char* buffer, uint32_t count, const char* separator)
{
	uint32_t ix = 0;
	while (ix < count - 1)
	{
		if (strchr(separator, buffer[ix]))
		{
			if (strchr(separator, buffer[ix + 1]))
			{
				/*ÕûÌåÓÒÒÆ*/
				uint32_t i = count++;
				buffer[i + 1] = 0;
				while (i > ix + 1)
				{
					buffer[i] = buffer[i - 1];
					i--;
				}
				buffer[i] = 0x7F;//Ìî³äÎª0x7F
			}
		}
		ix++;
	}
	return count;
}

uint8_t wt_converter_h2d(uint8_t value)
{
	uint8_t r;
	if (value >= '0' && value <= '9')
	{
		r = value - '0';
	}
	else if (value >= 'A' && value <= 'F')
	{
		r = value - '7';
	}
	else if (value >= 'a' && value <= 'f')
	{
		r = value - 'W';
	}
	else
	{
		r = 16;
	}
	return r;
}

uint8_t wt_converter_d2h(uint8_t value)
{
	uint8_t r;
	if (value < 10)
	{
		r = value + '0';
	}
	else if (value < 16)
	{
		r = value - 10 + 'A';
	}
	else
	{
		r = 'G';
	}
	return r;
}

uint32_t wt_converter_hs2b(uint8_t* buffer, uint32_t count)
{
	uint32_t cnt = 0;
	for (uint32_t i = 0; i < count; i += 2)
	{
		uint8_t h = wt_converter_h2d(buffer[i]);
		if (h < 16)
		{
			uint8_t l = wt_converter_h2d(buffer[i + 1]);
			if (l < 16)
			{
				buffer[cnt++] = h * 16 + l;
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
	return	cnt;
}

uint32_t wt_converter_b2hs(uint8_t* buffer, uint32_t count)
{
	uint32_t cnt = 0;
	for (uint32_t i = 0; i < count; i++)
	{
		buffer[count + i] = buffer[i];
	}
	for (uint32_t i = 0; i < count; i++)
	{
		uint8_t hl = buffer[count + i], v = wt_converter_d2h(hl / 16);
		if (v == 'G')
		{
			break;
		}
		else
		{
			buffer[cnt++] = v;
			v = wt_converter_d2h(hl % 16);
			if (v == 'G')
			{
				break;
			}
			else
			{
				buffer[cnt++] = v;
			}
		}
	}
	return cnt;
}
