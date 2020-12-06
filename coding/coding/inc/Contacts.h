#pragma once
#include "my_List.h"

#define CONTACTS_PATH "E:\\leedcode\\code\\code\\contacts.txt"
#define MAX_LINE 256
class CContacts
{
public:
	CContacts();
	virtual ~CContacts();

	int insert_person(const char* name, const char* phone);	//插入一个通讯录数据
	int del_person(const char* name);						//删除一个通讯录数据
	pPerson search_person(const char* name);					//查找一个通讯录数据
	void show_contacts();									//打印通讯录数据
	int load_contact(const char* path = CONTACTS_PATH);	//加载通讯录数据
	bool save_contacts();									//保存通讯录数据


private:	
	pPerson m_myContact;		//通讯录链表头
	int m_count;				//通讯录人数
	bool m_load;				//标识是否加载文件数据
	bool parser_token(char* buffer, int length, char* name, char* phone);	//字符解析
};

