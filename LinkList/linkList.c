#include <stdlib.h>
#include"utils.h"
#include"linkList.h"
void addNode(linkList* headNode, char* value, int length) {
	//创建一个新的节点，用malloc分配空间
	linkList* newNode = (linkList*)malloc(sizeof(linkList));
	newNode->value = (char*)malloc(length);
	strcpy(newNode->value, value);
	newNode->times = 0;
	newNode->nextNode = NULL;
	//如果链表的头部没有指向下一个节点，那么认为这个链表是第一次被修改
	if (headNode->nextNode == NULL) {
		headNode->nextNode = newNode;
		newNode->prevNode = headNode;
	}
	else {
		//否则我们找到链表末尾的节点，将其下个节点指针指向当前新节点
		linkList* p = headNode;
		while (p->nextNode != NULL) {
			p = p->nextNode;
		}
		newNode->value = value;
		newNode->prevNode = p;
		p->nextNode = newNode;
	}
}

void insertNode(linkList* thisNode, char* value)
{
	/*
	* thisNode指定一个节点
	*/
}

int findNode(linkList* head, char* value, linkList* p)
{
	//p指针用于返回所找到元素的位置
	p = head;
	//从头开始遍历，知道最后的一个节点
	while (p->nextNode)
	{
		if (p->value == value)
		{
			p->times++;
			return 1;
		}
		p = p->nextNode;
	}
	return 0;
	
	
}
