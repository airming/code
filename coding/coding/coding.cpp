// code.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <ctype.h>
#include <string>
#include <Contacts.h>

void printchar(char* str)
{
	if (str == nullptr)
	{
		return;
	}
	char ch;
	while (*str != '\0')
	{
		ch = *str;
		printf("%c\n", ch);
		str++;
	}
}


#define SEPARATOR_STATE 0 //分隔符状态
#define WORD_STATE 1 //单词状态
#define INIT_STATE SEPARATOR_STATE

int count_word(const char* path)
{
	int count = 0;
	int state = INIT_STATE;
	FILE *fp = fopen(path, "r");
	if (nullptr == fp)
	{
		return count;
	}

	int ch;

	while ((ch = fgetc(fp)) != EOF)
	{
		if (!isalpha(ch))	//非字母则为分割符，切换为分割符状态
		{
			state = SEPARATOR_STATE;
		}
		else if (state == SEPARATOR_STATE) //分割符状态， 输入是字母，切换为单词状态
		{
			state = WORD_STATE;
			count++;
		}
	}

	fclose(fp);
	return count;
}
enum MyEnum
{
	OPERATE_ADD = 1,
	OPERATE_DEL,
	OPERATE_SEARCH,
	OPERATE_SHOW,
	OPERATE_SAVE,
};

void show_menu()
{
	printf("*********************************************************\n");
	printf("****1: add person               2: del person************\n");
	printf("****3: serach person            4: show person***********\n");
	printf("****5: save contacts            *************************\n");
	printf("***** Other Key for exiting program *********************\n");
	printf("*********************************************************\n");
}

void insert_person(CContacts *contacts)
{
	char name[MAX_NAME];
	char phone[MAX_PHONE];
	INFO("plase enter name\n");
	scanf("%s", &name);

	INFO("plase enter phone\n");
	scanf("%s", &phone);
	contacts->insert_person(name, phone);
}

void del_person(CContacts *contacts)
{
	char name[MAX_NAME];
	INFO("plase enter name\n");
	scanf("%s", &name);
	contacts->del_person(name);
}

void search_person(CContacts *contacts)
{
	char name[MAX_NAME];
	INFO("plase enter name\n");
	scanf("%s", &name);
	pPerson item = contacts->search_person(name);
	if (nullptr == item)
	{
		INFO("not find\n");
		return;
	}
	INFO("person info name:%s, phone:%s\n", item->name, item->phone);
}

void show_person(CContacts *contacts)
{
	contacts->show_contacts();
}

#define FD_SETSIZE      1024
typedef unsigned long   fd_mask;
#define NBBY    8               /* number of bits in a byte */
#define NFDBITS (sizeof(fd_mask) * NBBY)        /* bits per mask */
#define howmany(x, y)   (((x) + ((y) - 1)) / (y))


#include "Cbst.h"

int _tmain(int argc, _TCHAR* argv[])
{
/*	int n = howmany(FD_SETSIZE, NFDBITS);
	int b = 1125 / NFDBITS;
	show_menu();
	CContacts *contacts = new CContacts();
	contacts->load_contact();*/


	Cbst *temp = new(Cbst);

	temp->insertNode(10);
	temp->insertNode(9);
	temp->insertNode(11);
	temp->insertNode(8);
	temp->insertNode(6);
	temp->insertNode(7);
	temp->insertNode(9);
	temp->insertNode(20);
	temp->insertNode(26);
	temp->insertNode(15);
	temp->insertNode(14);
	temp->insertNode(16);
	temp->insertNode(25);
	temp->insertNode(30);

	temp->searchNode(10);
	temp->searchNode(11);
	temp->searchNode(6);
	temp->searchNode(20);
	temp->searchNode(7);
	temp->searchNode(15);
	temp->searchNode(25);

	temp->printTree();


/*	while (true)
	{
		int my_select = 0;
		scanf("%d", &my_select);
		switch (my_select)
		{
		case OPERATE_ADD:
			insert_person(contacts);
			break;
		case OPERATE_DEL:
			del_person(contacts);
			break;
		case OPERATE_SEARCH:
			search_person(contacts);
			break;
		case OPERATE_SHOW:
			show_person(contacts);
			break;
		case OPERATE_SAVE:
			contacts->save_contacts();
			break;
		default:
			goto exit;
			break;
		}
		show_menu();
	}*/


exit:
	return 0;
}

