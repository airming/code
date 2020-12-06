#include "Contacts.h"
#include <stdlib.h>
#include <string>

CContacts::CContacts()
{
	m_count = 0;
	pPerson p = (pPerson)malloc(sizeof(Person));
	p->next = nullptr;
	p->pre = nullptr;
	m_myContact = p;
	m_load = false;
}


CContacts::~CContacts()
{
	save_contacts();		//保存文件
	for (pPerson item = m_myContact; item != nullptr; item = item->next)
	{
		if (item->next)
		{
			item->next->pre = nullptr;
		}
		free(item);
	}
	m_load = false;
}

bool CContacts::parser_token(char* buffer, int length, char* name, char* phone)
{
	if (nullptr == buffer || buffer[0] == '\0' || buffer[0] == '\n')
	{
		return false;
	}
	int i = 0;
	int state = 0;
	int j = 0;
	for (; i < length; ++i)
	{
		if (buffer[i] == ':')
		{
			state = 1;
		}		
		else if (buffer[i] == ',')
		{
			++i;
			break;
		}
		else if (state == 1)
		{
			name[j++] = buffer[i];
		}
	}

	state = 0;
	j = 0;
	for (; i < length; ++i)
	{
		if (buffer[i] == ':')
		{
			state = 1;
		}
		else if (buffer[i] == ',' || buffer[i] == '\0')
		{
			break;
		}
		else if (state == 1)
		{
			phone[j++] = buffer[i];
		}
		
	}
	return true;
}

int CContacts::load_contact(const char* path /*= CONTACTS_PATH*/)
{
	if (!m_load)		//从文件中加载通讯录数据
	{
		m_load = true;
		FILE *fp = fopen(path, "r");
		while (!feof(fp))
		{
			char name[MAX_NAME] = { 0 };
			char phone[MAX_PHONE] = { 0 };
			char buffer[MAX_LINE] = { 0 };
			fgets(buffer, MAX_LINE, fp);

			if (parser_token(buffer, MAX_LINE, name, phone))
			{
				insert_person(name, phone);
			}		
			
		}		
		fclose(fp);
		INFO("contacts load success\n");
	}
	return 0;
}

pPerson CContacts::search_person(const char* name)
{
	load_contact();
	pPerson item = m_myContact;
	for (; item != nullptr; item = item->next)
	{
		if (0 == strcmp(name, item->name))
		{
			return item;
		}
	}
	return nullptr;
}

int CContacts::insert_person(const char* name, const char* phone)
{
	load_contact();
	pPerson find_person = search_person(name);
	if (nullptr == find_person)		//不存在则插入数据
	{
		pPerson p = (pPerson)malloc(sizeof(Person));
		strcpy(p->name, name);
		strcpy(p->phone, phone);
		LIST_INSERT(m_myContact, p);
		m_count++;
		INFO("insert_person insert success, name:%s,phone:%s\n", name, phone);
	}
	else		//存在直接更新电话
	{
		strcpy(find_person->phone, phone);
		INFO("insert_person modify success, name:%s,phone:%s\n", name, phone);
	}
	return 0;
}

int CContacts::del_person(const char* name)
{
	load_contact();
	pPerson find_person = search_person(name);
	if (find_person)	//存在则删除对应的节点
	{
		LIST_DEL(m_myContact, find_person);
		free(find_person);
		m_count--;
		INFO("del_person del success, name:%s\n", name);
	}
	return 0;
}

void CContacts::show_contacts()
{
	for (pPerson item = m_myContact->next; item != nullptr; item = item->next)
	{
		printf("name:%s, phone:%s\n", item->name, item->phone);
	}
}

bool CContacts::save_contacts()
{
	FILE *fp = fopen(CONTACTS_PATH, "w");
	for (pPerson item = m_myContact->next; item != nullptr; item = item->next)
	{		
		fprintf(fp, "name:%s,phone:%s\n", item->name, item->phone);
		fflush(fp);
	}
	fclose(fp);
	return true;
}
