/*******************************************
//由于基于数组的栈有太多的的弊端，比如在增容方面。
//因此本模块实现了基于单链表的栈，利用单链表的某些
//操作来实现元素初始化，压栈，弹出，清空等操作
*******************************************/
#include <iostream>
using namespace std;

typedef int StackElemType;
typedef struct StackNode{
	StackElemType data;
	int nodeCount; //节点计数（有效节点的个数）,当仅有空的头节点时为0
	struct StackNode* _next;
}StackNode;

class MyStack{
public:
	//在构造函数里进行链栈的初始化
	MyStack()
	{	//初始化一个带头的空的节点，节点的next指向空
	    pHead = buyNewNode();
		pHead->_next = nullptr;
		pHead->nodeCount = 0;
		cout << "链栈已初始化完毕!" << endl;
	}
	~MyStack() 
	{	
	}
	//申请新的节点
	StackNode* buyNewNode()
	{
		StackNode* newNode = new StackNode();
		return newNode;
	}

	//元素入栈(链栈的压栈可以用链表的头插法来实现)
	void pushData(StackElemType data)
	{
		StackNode* newNode = buyNewNode();
		newNode->data = data;
		//如果此时链表没有有效元素
		if (pHead->_next == nullptr)
		{
			pHead->_next = newNode;
			newNode->_next = nullptr;
			++pHead->nodeCount;
		}
		else
		{
			newNode->_next = pHead->_next;
			pHead->_next = newNode;
			++pHead->nodeCount;
		}
	}

	//元素出栈（头删的操作）
	void popData()
	{
		//若无有效元素，则提示
		if (pHead->_next == nullptr)
		{
			cout << "链栈内无有效元素，出栈失败!" << endl;
		}
		//若仅有一个有效元素
		else if (pHead->_next != nullptr && pHead->_next->_next == nullptr)
		{
			StackNode* pFirst = pHead->_next;
			delete pFirst;
			pFirst = nullptr;
			--pHead->nodeCount;
		}
		//若有若干个元素
		else
		{
			StackNode* pFirst = pHead->_next;
			pHead->_next = pFirst->_next;
			delete pFirst;
			pFirst = nullptr;
			--pHead->nodeCount;
		}
	}
	//打印链栈内元素
	void printLinkStack()
	{
		if (pHead->_next == nullptr)
		{
			cout << "链栈内无有效元素!" << endl;
		}
		else
		{
			StackNode* pCur = pHead->_next;
			while (pCur != nullptr)
			{
				cout << pCur->data <<endl;
				pCur = pCur->_next;
			}
			cout << endl;
		}
		return;
	}

	//获取链栈元素的个数
	int getCount()
	{
		return pHead->nodeCount;
	}

	//销毁链栈
	void destroyLinkStack()
	{
		//如果仅有一个有效元素
		if (pHead->_next != nullptr && pHead->_next->_next == nullptr)
		{
			StackNode* pFirst = pHead->_next;
			delete pFirst;
			pFirst = nullptr;
			pHead->nodeCount = 0;
		}
		if (pHead->_next != nullptr && pHead->_next->_next != nullptr)
		{

			StackNode* pFirst = pHead->_next;
			while (pFirst != nullptr)
			{
				StackNode* pDel = pFirst;
				pHead->_next = pFirst->_next;
				delete pDel;
				pDel = nullptr;
				pFirst = pHead->_next;
				--pHead->nodeCount;
			}
		}
		cout << "链栈销毁完毕!" << endl;
	}
private:
	StackNode* pHead;
};