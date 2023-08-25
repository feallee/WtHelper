#include <stdlib.h>
#include <assert.h>
#include "wt_mealy.h"

typedef struct
{
	const wt_mealy_transit_t* transitTable;
	unsigned short transitCount;
	char currentState;
	char finalState;
}Machine;

wt_mealy_t wt_mealy_create(void)
{
	return calloc(1, sizeof(Machine));
}

void wt_mealy_start(wt_mealy_t mealy, const wt_mealy_transit_t* transitTable, unsigned short transitCount, char initialState, char finalState)
{
	Machine* m;
	assert(mealy);
	assert(transitTable);
	assert(transitCount);
	assert(initialState != WT_MEALY_STATE_UNKNOWN);
	assert(finalState != WT_MEALY_STATE_UNKNOWN);
	m = mealy;
	m->transitTable = transitTable;
	m->transitCount = transitCount;
	m->currentState = initialState;
	m->finalState = finalState;
}

char wt_mealy_raise(wt_mealy_t mealy, char event, size_t parameter)
{
	char to;
	Machine* m;
	assert(mealy);
	assert(event != WT_MEALY_STATE_UNKNOWN);
	m = mealy;
	assert(m->transitTable);
	to = WT_MEALY_STATE_UNKNOWN;
	if (m->currentState != m->finalState)
	{
		unsigned short cnt = m->transitCount;
		const wt_mealy_transit_t* tran = m->transitTable;
		while (cnt--)
		{
			if ((tran->current == m->currentState) &&
				(tran->event == event))
			{
				char from = m->currentState;
				m->currentState = to = tran->next;
				if (tran->action)
				{
					tran->action(from, to, event, parameter);
				}
				break;
			}
			tran++;
		}
	}
	return to;
}

char wt_mealy_getcurrent(wt_mealy_t mealy)
{
	assert(mealy);
	return ((Machine*)mealy)->currentState;
}

void wt_mealy_delete(wt_mealy_t mealy)
{
	free(mealy);
}

char* wt_mealy_getversion(void)
{
	return "1.0";
}