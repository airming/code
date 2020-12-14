#include "Cbst.h"
#include <stdlib.h>
#include <stdio.h>

Cbst::Cbst()
{
	m_root = nullptr;
}

Cbst::~Cbst()
{

}

void Cbst::insertNode(int val, pNode insNode /*= nullptr*/)
{
	if (m_root == nullptr) //��ʼ�����ڵ�
	{
		m_root = new(Node);
		m_root->val = val;
		return;
	}
	
	if (insNode == nullptr) //������ǿսڵ������д���
	{
		insNode = m_root;
	}

	if (val < insNode->val) //�ȸ�С���뵽���֧
	{
		if (insNode->lchild == nullptr) //��������ڵ㣬ֱ�Ӳ��뵽��ڵ���
		{
			pNode ptemp = new(Node);
			ptemp->val = val;
			insNode->lchild = ptemp;
		}
		else //��������뵽������
		{
			insertNode(val, insNode->lchild);
		}
	}
	else if (val == insNode->val) //����ڵ�ֵ��ȣ�������һ
	{
		insNode->count++;		
	}
	else				//�ȸ��ڵ����뵽�ҷ�֧
	{
		if (insNode->rchild == nullptr) //�������ҽڵ㣬ֱ�Ӳ��뵽�ҽڵ���
		{
			pNode ptemp = new(Node);
			ptemp->val = val;
			insNode->rchild = ptemp;
		}
		else //�����ҽڵ�����뵽������
		{
			insertNode(val, insNode->rchild);
		}		
	}
}


pNode Cbst::searchNode(int val, pNode insNode /*= nullptr*/)
{
	static int count = 0;
	if (m_root == nullptr)
	{
		printf("val = %d, level = 0\n", val);
		return nullptr;
	}

	if (insNode == nullptr)
	{
		count = 1;
		insNode = m_root;
	}
	else
	{
		count++;
	}

	if (val < insNode->val)
	{
		if (insNode->lchild == nullptr) //û����ڵ���ֱ�ӷ���
		{
			printf("va1 = %d, level = 0\n", val);
			return nullptr;
		}
		searchNode(val, insNode->lchild);
	}
	else if (val == insNode->val)
	{
		printf("val = %d, level = %d\n", val, count);
		return insNode;
	}
	else if (val > insNode->val)
	{
		if (insNode->rchild == nullptr) //û���ҽڵ���ֱ�ӷ���
		{
			printf("va1 = %d, level = 0\n", val);
			return nullptr;
		}
		searchNode(val, insNode->rchild);
	}
	
}

bool Cbst::delNode(int val, pNode insNode /*= nullptr*/)
{
	pNode pTemp = searchNode(val);
	if (pTemp == nullptr)
	{
		return;
	}
	if (pTemp->rchild == nullptr) //�������ҽڵ㣬ֱ��ʹ�øýڵ����ڵ��滻�Լ�
	{

	}
	return true;
}


void Cbst::printTree()
{
	listNode(m_root);
}


//�ñ�����ȡ������������մ�С�����
void Cbst::listNode(pNode insNode)
{	

	if (insNode == nullptr) //�Ӹ��ڵ㿪ʼ��ӡ
	{
		return;
	}

	listNode(insNode->lchild);
	for (int i = 0; i < insNode->count; ++i)
	{
		printf("val = %d\n", insNode->val);
	}
	
	listNode(insNode->rchild);		

}




