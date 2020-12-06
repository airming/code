#include <stdio.h>

#define MAX_NAME 64			//���ֳ���
#define MAX_PHONE 16		//�绰����
#define INFO printf			//�򻯵�����Ϣ

typedef struct Person
{
	char name[MAX_NAME];
	char phone[MAX_PHONE];
	struct Person* pre;
	struct Person* next;

}Person, *pPerson;

//�����в���һ���ڵ㣬�������Ǵ�ͷ���ĵ�����
#define LIST_INSERT(head, item) do{	\
	if (head && item && head != item){	\
		item->next = head->next; \
		item->pre = head;	\
		if (head->next){head->next->pre = item;}\
		head->next = item;	\
	}	\
}while (0);

//������ɾ��һ���ڵ�
#define LIST_DEL(head, item) do {	\
	if (item && head != item){ \
		if (item->pre){ item->pre->next = item->next;} \
		if (item->next){item->next->pre = item->pre;} \
	}\
} while (0);

