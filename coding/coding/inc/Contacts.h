#pragma once
#include "my_List.h"

#define CONTACTS_PATH "E:\\leedcode\\code\\code\\contacts.txt"
#define MAX_LINE 256
class CContacts
{
public:
	CContacts();
	virtual ~CContacts();

	int insert_person(const char* name, const char* phone);	//����һ��ͨѶ¼����
	int del_person(const char* name);						//ɾ��һ��ͨѶ¼����
	pPerson search_person(const char* name);					//����һ��ͨѶ¼����
	void show_contacts();									//��ӡͨѶ¼����
	int load_contact(const char* path = CONTACTS_PATH);	//����ͨѶ¼����
	bool save_contacts();									//����ͨѶ¼����


private:	
	pPerson m_myContact;		//ͨѶ¼����ͷ
	int m_count;				//ͨѶ¼����
	bool m_load;				//��ʶ�Ƿ�����ļ�����
	bool parser_token(char* buffer, int length, char* name, char* phone);	//�ַ�����
};

