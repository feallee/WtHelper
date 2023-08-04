#include "wt_mealy.h"
#include <stdlib.h>

typedef struct
{
	mealy_transit_t* transitTable;
	unsigned short transitCount;
	char currentState;
	char finalState;
}machine_t;

mealy_t mealy_create(const mealy_transit_t* transitTable, unsigned short transitCount, char initialState, char finalState)
{
	machine_t* r = NULL;
	if (transitTable &&
		transitCount &&
		(initialState != MEALY_STATE_UNKNOWN) &&
		(finalState != MEALY_STATE_UNKNOWN))
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

char mealy_raise(mealy_t mealy, char event, void* parameter)
{
	char r = MEALY_STATE_UNKNOWN;
	if (mealy &&
		(event != MEALY_STATE_UNKNOWN))
	{
		machine_t* m = mealy;
		if (m->currentState != m->finalState)
		{
			unsigned short cnt = m->transitCount;
			mealy_transit_t* tran = m->transitTable;
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

char mealy_get_current(mealy_t mealy)
{
	char r = MEALY_STATE_UNKNOWN;
	if (mealy)
	{
		r = ((machine_t*)mealy)->currentState;
	}
	return r;
}

void mealy_delete(mealy_t mealy)
{
	free(mealy);
}
