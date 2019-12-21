/*******************************************
//���ڻ��������ջ��̫��ĵı׶ˣ����������ݷ��档
//��˱�ģ��ʵ���˻��ڵ������ջ�����õ������ĳЩ
//������ʵ��Ԫ�س�ʼ����ѹջ����������յȲ���
*******************************************/
#include <iostream>
using namespace std;

typedef int StackElemType;
typedef struct StackNode{
	StackElemType data;
	int nodeCount; //�ڵ��������Ч�ڵ�ĸ�����,�����пյ�ͷ�ڵ�ʱΪ0
	struct StackNode* _next;
}StackNode;

class MyStack{
public:
	//�ڹ��캯���������ջ�ĳ�ʼ��
	MyStack()
	{	//��ʼ��һ����ͷ�ĿյĽڵ㣬�ڵ��nextָ���
	    pHead = buyNewNode();
		pHead->_next = nullptr;
		pHead->nodeCount = 0;
		cout << "��ջ�ѳ�ʼ�����!" << endl;
	}
	~MyStack() 
	{	
	}
	//�����µĽڵ�
	StackNode* buyNewNode()
	{
		StackNode* newNode = new StackNode();
		return newNode;
	}

	//Ԫ����ջ(��ջ��ѹջ�����������ͷ�巨��ʵ��)
	void pushData(StackElemType data)
	{
		StackNode* newNode = buyNewNode();
		newNode->data = data;
		//�����ʱ����û����ЧԪ��
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

	//Ԫ�س�ջ��ͷɾ�Ĳ�����
	void popData()
	{
		//������ЧԪ�أ�����ʾ
		if (pHead->_next == nullptr)
		{
			cout << "��ջ������ЧԪ�أ���ջʧ��!" << endl;
		}
		//������һ����ЧԪ��
		else if (pHead->_next != nullptr && pHead->_next->_next == nullptr)
		{
			StackNode* pFirst = pHead->_next;
			delete pFirst;
			pFirst = nullptr;
			--pHead->nodeCount;
		}
		//�������ɸ�Ԫ��
		else
		{
			StackNode* pFirst = pHead->_next;
			pHead->_next = pFirst->_next;
			delete pFirst;
			pFirst = nullptr;
			--pHead->nodeCount;
		}
	}
	//��ӡ��ջ��Ԫ��
	void printLinkStack()
	{
		if (pHead->_next == nullptr)
		{
			cout << "��ջ������ЧԪ��!" << endl;
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

	//��ȡ��ջԪ�صĸ���
	int getCount()
	{
		return pHead->nodeCount;
	}

	//������ջ
	void destroyLinkStack()
	{
		//�������һ����ЧԪ��
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
		cout << "��ջ�������!" << endl;
	}
private:
	StackNode* pHead;
};