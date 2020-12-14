#pragma once

/*** һ��������������㷨�ṹ����������������ڵ��ֵС�ڸ��ڵ㣬���ڵ��ֵС���ҽڵ㣬һ�����в���
��������ֵ��ȵ������ڵ㣬�˴����ظ��ڵ�����ø�����ֵ�����棬ʱ�临�Ӷ�Ϊlogn

*/
typedef struct Node
{
	int val;					//�ڵ��ֵ
	int count;					//�ڵ�ֵ�ĸ���
	struct Node* lchild;		//��ڵ�
	struct Node* rchild;		//�ҽڵ�

	Node(){						//��ʼ������
		val = 0;
		count = 1;
		lchild = nullptr;
		rchild = nullptr;
	}
}Node,*pNode;


class Cbst
{
public:
	Cbst();
	~Cbst();

	void insertNode(int val, pNode insNode = nullptr);		//����һ���ڵ�
	pNode searchNode(int val, pNode insNode = nullptr);		//��ѯһ���ڵ�,��ӡ���ýڵ����ڵĲ�
	bool delNode(int val, pNode insNode = nullptr);			//ɾ��һ���ڵ�
	void printTree();										//����������

private:
	void listNode(pNode insNode);				//��������
	pNode m_root;		//���ĸ�
};

