#include "wt_mealy.h"

void wt_mealy_init(wt_mealy_machine_type* machine, const wt_mealy_transition_type* table, uint16_t count, char initial, char final)
{
	machine->table = table;
	machine->count = count;
	machine->current = initial;
	machine->final = final;
}

bool wt_mealy_raise(wt_mealy_machine_type* machine, char event, void* parameter)
{
	bool r = false;
	if (machine->current != machine->final)
	{
		for (uint16_t i = 0; i < machine->count; i++)
		{
			wt_mealy_transition_type* t = (&machine->table[i]);
			char from = machine->current;
			if (t->state == machine->current && t->event == event)
			{
				machine->current = t->next;
				if (t->action)
				{
					t->action(from, t->next, event, parameter);
				}
				r = true;
				break;
			}
		}
	}
	return r;
}

char wt_mealy_getstate(wt_mealy_machine_type* machine)
{
	return machine->current;
}

bool wt_mealy_isfinal(wt_mealy_machine_type* machine)
{
	return machine->current == machine->final;
}