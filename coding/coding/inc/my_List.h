#include <stdio.h>

#define MAX_NAME 64			//名字长度
#define MAX_PHONE 16		//电话长度
#define INFO printf			//简化调试信息

typedef struct Person
{
	char name[MAX_NAME];
	char phone[MAX_PHONE];
	struct Person* pre;
	struct Person* next;

}Person, *pPerson;

//链表中插入一个节点，该链表是带头结点的单链表
#define LIST_INSERT(head, item) do{	\
	if (head && item && head != item){	\
		item->next = head->next; \
		item->pre = head;	\
		if (head->next){head->next->pre = item;}\
		head->next = item;	\
	}	\
}while (0);

//链表中删除一个节点
#define LIST_DEL(head, item) do {	\
	if (item && head != item){ \
		if (item->pre){ item->pre->next = item->next;} \
		if (item->next){item->next->pre = item->pre;} \
	}\
} while (0);

