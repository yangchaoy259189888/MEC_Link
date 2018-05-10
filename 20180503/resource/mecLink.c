#include <stdio.h>
#include <malloc.h>

#include "../include/mec.h"
#include "../include/mecLink.h"

int indexOfLink(const LINK *head, const void *orgData,
		int (*cmp)(const void *, const void *)) {
	int index;
	const LINK *p;
	const void *data;
	
	if(NULL == orgData) {
		return NOT_FOUND;
	}
	if(NULL == head) {
		return NOT_FOUND;
	}
	
	for(p = head, index = 0; NULL != p; p = p->next, index++) {
		data = p->data;
		if(data == orgData || cmp(orgData, data) == 0) {
			return index;
		}
	}
	
	return NOT_FOUND;
}

void appendLinkNode(LINK **headPoint, void *data) {
	LINK *p;
	LINK *newNode;
	
	if(NULL == headPoint) {
		return;
	}
	
	// 查找末节点
	for(p = *headPoint; NULL != p && NULL != p->next; p = p->next) {
	}
	// 查找结果有两种情况：
	// 1、p值为NULL；说明当前链表是空链；需要将节点直接链到头指针的后面；
	// 2、p值非NULL；说明当前链表非空，且p所指向的就是末节点；只需要将
	//		节点链接到末节点的后面。
	// 上面都提到“节点”，但是，这个节点尚不存在。于是，需要先申请这个节点。
	
	newNode = (LINK *) malloc(sizeof(LINK));
	newNode->data = data;
	newNode->next = NULL;
	
	if(NULL == p) {
		*headPoint = newNode;
	} else {
		p->next = newNode;
	}
}
