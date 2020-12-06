#include "../stdafx.h"
#include "../inc/CMyString.h"
#include <string>

CMyString::CMyString(char* pData /*= NULL*/)
{
	if (pData == NULL)
	{
		m_pDate = (char*)malloc(1);
	}
	else
	{
		int nLen = strlen(pData);
		m_pDate = (char*)malloc(nLen + 1);
		strcpy(m_pDate, pData);
	}
}

CMyString::CMyString(const CMyString& str)
{
	int nLen = strlen(str.m_pDate);
	m_pDate = (char*)malloc(nLen + 1);
	strcpy(m_pDate, str.m_pDate);
}

CMyString::~CMyString()
{
	free(m_pDate);
}

CMyString& CMyString::operator=(const CMyString& str)
{
	if (this == &str)
	{
		return *this;
	}
	free(m_pDate);
	int nLen = strlen(str.m_pDate);
	m_pDate = (char*)malloc(nLen + 1);
	strcpy(m_pDate, str.m_pDate);
	return *this;
}

void CMyString::print()
{
	printf("%s\n", m_pDate);
}