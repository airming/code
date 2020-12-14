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
	if (m_root == nullptr) //初始化根节点
	{
		m_root = new(Node);
		m_root->val = val;
		return;
	}
	
	if (insNode == nullptr) //传入的是空节点对其进行创建
	{
		insNode = m_root;
	}

	if (val < insNode->val) //比根小插入到左分支
	{
		if (insNode->lchild == nullptr) //不存在左节点，直接插入到左节点上
		{
			pNode ptemp = new(Node);
			ptemp->val = val;
			insNode->lchild = ptemp;
		}
		else //存在则插入到左树上
		{
			insertNode(val, insNode->lchild);
		}
	}
	else if (val == insNode->val) //与根节点值相等，计数加一
	{
		insNode->count++;		
	}
	else				//比根节点大加入到右分支
	{
		if (insNode->rchild == nullptr) //不存在右节点，直接插入到右节点上
		{
			pNode ptemp = new(Node);
			ptemp->val = val;
			insNode->rchild = ptemp;
		}
		else //存在右节点则插入到右树上
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
		if (insNode->lchild == nullptr) //没有左节点则直接返回
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
		if (insNode->rchild == nullptr) //没有右节点则直接返回
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
	if (pTemp->rchild == nullptr) //不存在右节点，直接使用该节点的左节点替换自己
	{

	}
	return true;
}


void Cbst::printTree()
{
	listNode(m_root);
}


//该遍历采取中序变量，按照从小打到输出
void Cbst::listNode(pNode insNode)
{	

	if (insNode == nullptr) //从根节点开始打印
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




