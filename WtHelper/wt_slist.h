#ifndef __WT_SLIST_H_

typedef struct wt_slist_t
{
	struct wt_slist_t* next;
}wt_slist_t;


static __inline void  wt_slist_initialize(wt_slist_t* l)
{
	l->next = 0;
}

static __inline void wt_slist_append(wt_slist_t* l, wt_slist_t* n)
{
	wt_slist_t* node = l;
	while (node->next) node = node->next;
	node->next = n;
	n->next = 0;
}

static __inline void wt_slist_insert(wt_slist_t* l, wt_slist_t* n)
{
	n->next = l->next;
	l->next = n;
}

static __inline unsigned int wt_slist_count(const wt_slist_t* l)
{
	unsigned int len = 0;
	const wt_slist_t* list = l->next;
	while (list)
	{
		list = list->next;
		len++;
	}
	return len;
}

static __inline wt_slist_t* wt_slist_remove(wt_slist_t* l, wt_slist_t* n)
{
	wt_slist_t* node = l;
	while (node->next && node->next != n) node = node->next;
	if (node->next) node->next = node->next->next;
	return l;
}

static __inline wt_slist_t* wt_slist_first(wt_slist_t* l)
{
	return l->next;
}

static __inline wt_slist_t* wt_slist_last(wt_slist_t* l)
{
	while (l->next) l = l->next;
	return l;
}

static __inline int wt_slist_isempty(wt_slist_t* l)
{
	return l->next == 0;
}

#define wt_slist_for_each(pos, head) \
    for (pos = (head)->next; pos != 0; pos = pos->next)

#endif // !__WT_SLIST_H_
