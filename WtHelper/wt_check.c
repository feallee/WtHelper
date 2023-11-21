#include "wt_check.h"
uint8_t wt_check_cs8(const uint8_t* buffer, uint32_t count)
{
	uint8_t r = 0;
	while (count--)
	{
		r += buffer[count];
	}
	return r;
}

uint16_t wt_check_cs16(const uint8_t* buffer, uint32_t count)
{
	uint16_t r = 0;
	while (count--)
	{
		r += buffer[count];
	}
	return r;
}
uint32_t wt_check_cs32(const uint8_t* buffer, uint32_t count)
{
	uint32_t r = 0;
	while (count--)
	{
		r += buffer[count];
	}
	return r;
}


uint8_t wt_check_bcc(const uint8_t* buffer, uint32_t count)
{
	uint8_t r = 0;
	while (count--)
	{
		r ^= buffer[count];
	}
	return r;
}