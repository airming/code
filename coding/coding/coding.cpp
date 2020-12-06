// code.cpp : �������̨Ӧ�ó������ڵ㡣
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


#define SEPARATOR_STATE 0 //�ָ���״̬
#define WORD_STATE 1 //����״̬
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
		if (!isalpha(ch))	//����ĸ��Ϊ�ָ�����л�Ϊ�ָ��״̬
		{
			state = SEPARATOR_STATE;
		}
		else if (state == SEPARATOR_STATE) //�ָ��״̬�� ��������ĸ���л�Ϊ����״̬
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

int _tmain(int argc, _TCHAR* argv[])
{
	show_menu();
	CContacts *contacts = new CContacts();
	contacts->load_contact();

	while (true)
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
	}


exit:
	return 0;
}

