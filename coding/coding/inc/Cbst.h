#pragma once

/*** 一个二叉查找树的算法结构，二叉查找树概念：左节点的值小于根节点，根节点的值小于右节点，一颗树中不会
存在两个值相等的两个节点，此处的重复节点可以用个计数值来保存，时间复杂度为logn

*/
typedef struct Node
{
	int val;					//节点的值
	int count;					//节点值的个数
	struct Node* lchild;		//左节点
	struct Node* rchild;		//右节点

	Node(){						//初始化变量
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

	void insertNode(int val, pNode insNode = nullptr);		//插入一个节点
	pNode searchNode(int val, pNode insNode = nullptr);		//查询一个节点,打印出该节点所在的层
	bool delNode(int val, pNode insNode = nullptr);			//删除一个节点
	void printTree();										//遍历整个树

private:
	void listNode(pNode insNode);				//遍历该树
	pNode m_root;		//树的根
};

