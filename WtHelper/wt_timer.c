#include <stdlib.h>
#include <assert.h>
#include "wt_slist.h"
#include "wt_timer.h"
typedef struct
{
	wt_slist_t list;
	unsigned int interval;
	unsigned int count;
	void(*timed)(void);
}Timer;

static wt_slist_t Container = { NULL };

wt_timer_t wt_timer_create(unsigned int interval, void(*timed)(void))
{
	Timer* t;
	assert(timed);
	assert(interval);
	t = malloc(sizeof(Timer));
	if (t)
	{
		t->interval = interval;
		t->count = interval;
		t->timed = timed;
		wt_slist_append(&Container, (wt_slist_t*)t);
	}
	return t;
}

void wt_timer_refresh(void)
{
	wt_slist_t* l;
	Timer* t;
	wt_slist_for_each(l, &Container)
	{
		t = (Timer*)l;
		if (t->count > 1)
		{
			t->count--;
		}
	}
}

void wt_timer_dowork(void)
{
	wt_slist_t* l;
	Timer* t;
	wt_slist_for_each(l, &Container)
	{
		t = (Timer*)l;
		if (t->count == 1)
		{
			t->count = 0;
			t->timed();
		}
	}
}

void wt_timer_reset(wt_timer_t timer)
{
	Timer* t;
	assert(timer);
	t = timer;
	t->count = t->interval;
}

void wt_timer_delete(wt_timer_t timer)
{
	wt_slist_t* l;
	assert(timer);
	l = wt_slist_first(&Container);
	if (l)
	{
		wt_slist_remove(&Container, l);
		free(l);
	}
}