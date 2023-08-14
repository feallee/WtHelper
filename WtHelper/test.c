#include <stdio.h>

#include "wt_queue.h"
static void queue_test(void)
{
	char* str = "abc";
	size_t d;
	wt_queue_t q = wt_queue_create();
	wt_queue_enqueue(q, 100);
	wt_queue_enqueue(q, 200);
	wt_queue_enqueue(q, (size_t)str);
	wt_queue_dequeue(q, &d); printf("\ndequeue:100=%zd\n", d);
	wt_queue_peek(q, &d); printf("peek:200=%zd\n", d);
	wt_queue_dequeue(q, &d); printf("dequeue:200=%zd\n", d);
	wt_queue_dequeue(q, &d);
	printf("dequeue:abc=%s\n", (char*)d);
	wt_queue_delete(q);
}

#include "wt_buffer.h"
static void buffer_test(void)
{
	char c;
	wt_buffer_t b = wt_buffer_create(8);
	wt_buffer_putchar(b, 'A');
	wt_buffer_putchar(b, 'B');
	wt_buffer_putchar(b, 'C');
	wt_buffer_putchar(b, 'D');
	wt_buffer_putchar(b, 'E');
	wt_buffer_putchar(b, 'F');
	wt_buffer_putchar(b, 'G');
	printf("\nBuffer state:%d\n", wt_buffer_getsatate(b));
	wt_buffer_putchar(b, '8');
	printf("Buffer state:%d\n", wt_buffer_getsatate(b));
	wt_buffer_getchar(b, &c); printf("Get char:%c\n", c);
	wt_buffer_getchar(b, &c); printf("Get char:%c\n", c);
	wt_buffer_getchar(b, &c); printf("Get char:%c\n", c);
	wt_buffer_getchar(b, &c); printf("Get char:%c\n", c);
	printf("Buffer state:%d\n", wt_buffer_getsatate(b));
	wt_buffer_clear(b);
	printf("Buffer state:%d\n\n", wt_buffer_getsatate(b));
	wt_buffer_delete(b);
}


#include "wt_mealy.h"
#define MEALY_STATE_STOP 0
#define MEALY_STATE_PLAY 1
#define MEALY_STATE_PAUSE 2
#define MEALY_STATE_FINAL (-2)

#define MEALY_EVENT_PLAY_PAUSE 0
#define MEALY_EVENT_STOP 1

static void play_mp3(char from, char to, char event, size_t parameter)
{
	printf("From:%d,To:%d,Event:%d,Parameter:%zd -> Play mp3\n", from, to, event, parameter);
}

static void stop_mp3(char from, char to, char event, size_t parameter)
{
	printf("From:%d,To:%d,Event:%d,Parameter:%zd -> Stop mp3\n", from, to, event, parameter);
}

static void pause_mp3(char from, char to, char event, size_t parameter)
{
	printf("From:%d,To:%d,Event:%d,Parameter:%zd -> Pause mp3\n", from, to, event, parameter);
}

static void resume_mp3(char from, char to, char event, size_t parameter)
{
	printf("From:%d,To:%d,Event:%d,Parameter:%zd -> Resume mp3\n", from, to, event, parameter);
}

static const wt_mealy_transit_t trans[] =
{
	{MEALY_STATE_STOP,MEALY_EVENT_PLAY_PAUSE,MEALY_STATE_PLAY,play_mp3},
	{MEALY_STATE_PLAY,MEALY_EVENT_STOP,MEALY_STATE_STOP,stop_mp3},
	{MEALY_STATE_PLAY,MEALY_EVENT_PLAY_PAUSE,MEALY_STATE_PAUSE,pause_mp3},
	{MEALY_STATE_PAUSE,MEALY_EVENT_PLAY_PAUSE,MEALY_STATE_PLAY,resume_mp3},
	{MEALY_STATE_PAUSE,MEALY_EVENT_STOP,MEALY_STATE_STOP,stop_mp3},
};

void mealy_test(void)
{
	wt_mealy_t m = wt_mealy_create(
		trans,
		sizeof(trans) / sizeof(trans[0]),
		MEALY_STATE_STOP,
		MEALY_STATE_FINAL);

	printf("Current:%d\n", wt_mealy_getcurrent(m));
	wt_mealy_raise(m, MEALY_EVENT_PLAY_PAUSE, 0);
	wt_mealy_raise(m, MEALY_EVENT_PLAY_PAUSE, 0);
	wt_mealy_raise(m, MEALY_EVENT_STOP, 0);

	wt_mealy_raise(m, MEALY_EVENT_PLAY_PAUSE, 0);
	wt_mealy_raise(m, MEALY_EVENT_PLAY_PAUSE, 0);
	wt_mealy_raise(m, MEALY_EVENT_PLAY_PAUSE, 0);
	wt_mealy_raise(m, MEALY_EVENT_STOP, 0);
	printf("Current:%d\n", wt_mealy_getcurrent(m));
	wt_mealy_delete(m);
}

int main(void)
{
	queue_test();
	buffer_test();
	mealy_test();
	return 0;
}