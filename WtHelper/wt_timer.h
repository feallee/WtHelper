#ifndef __WT_TIMER_H_

typedef void* wt_timer_t;
typedef int (*wt_timer_timed)(void);

wt_timer_t wt_timer_create(unsigned int interval, void(*timed)(void));
void wt_timer_refresh(void);
void wt_timer_dowork(void);
void wt_timer_reset(wt_timer_t timer);
void wt_timer_delete(wt_timer_t timer);


#endif // !__WT_TIMER_H_
