#include <stdio.h>

#include "./include/mec.h"
#include "./include/mecLink.h"

typedef struct POINT {
	int row;
	int col;
}POINT;

int compare(const void *one, const void *other);

int compare(const void *first, const void *second) {
	const POINT *one = (const POINT *)first;
	const POINT *other = (const POINT *)second;

	if(one->row > other->row) {
		return 1;
	} else if(one->row < other->row) {
		return -1;
	}
	return 0;
}

int main() {
	LINK *head1 = NULL;
	POINT p1 = { 3, 4 };
	POINT p2 = { 3, 4 };
	POINT p3 = { 5, 6 };
	int index;
	
	appendLinkNode(&head1, &p3);
	appendLinkNode(&head1, &p1);
	index = indexOfLink(head1, &p2, compare);
	printf("%d\n", index);

	return 0;
}

