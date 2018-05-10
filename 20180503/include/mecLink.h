#ifndef _MEC_LINK_H_
#define _MEC_LINK_H_

typedef struct LINK {
	void *data;
	struct LINK *next;
}LINK;

void appendLinkNode(LINK **headPoint, void *data);
int indexOfLink(const LINK *head, const void *orgData,
		int (*cmp)(const void *, const void *));

#endif
