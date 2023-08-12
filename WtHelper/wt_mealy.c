#include <stdlib.h>
#include "wt_mealy.h"

typedef struct
{
	wt_mealy_transit_t* transitTable;
	unsigned short transitCount;
	char currentState;
	char finalState;
}machine_t;

wt_mealy_t wt_mealy_create(const wt_mealy_transit_t* transitTable, unsigned short transitCount, char initialState, char finalState)
{
	machine_t* r = NULL;
	if (transitTable &&
		transitCount &&
		(initialState != WT_MEALY_STATE_UNKNOWN) &&
		(finalState != WT_MEALY_STATE_UNKNOWN))
	{
		r = malloc(sizeof(machine_t));
		if (r)
		{
			r->transitTable = transitTable;
			r->transitCount = transitCount;
			r->currentState = initialState;
			r->finalState = finalState;
		}
	}
	return r;
}

char wt_mealy_raise(wt_mealy_t mealy, char event, void* parameter)
{
	char r = WT_MEALY_STATE_UNKNOWN;
	if (mealy &&
		(event != WT_MEALY_STATE_UNKNOWN))
	{
		machine_t* m = mealy;
		if (m->currentState != m->finalState)
		{
			unsigned short cnt = m->transitCount;
			wt_mealy_transit_t* tran = m->transitTable;
			while (cnt--)
			{
				if ((tran->current == m->currentState) &&
					(tran->event == event))
				{
					m->currentState = r = tran->next;
					if (tran->action)
					{
						tran->action(parameter);
					}
					break;
				}
				tran++;
			}
		}
	}
	return r;
}

char wt_mealy_getcurrent(wt_mealy_t mealy)
{
	char r = WT_MEALY_STATE_UNKNOWN;
	if (mealy)
	{
		r = ((machine_t*)mealy)->currentState;
	}
	return r;
}

void wt_mealy_delete(wt_mealy_t mealy)
{
	free(mealy);
}
