#include "linklistStack.h"

int main()
{

	MyStack myStack;
	int count = 0;  //��ջԪ�صĸ���
	cout << "��ջ" << endl;
	myStack.pushData(1);
	myStack.pushData(2);
	myStack.pushData(3);
	myStack.pushData(4);
	myStack.pushData(5);
	myStack.printLinkStack();

	cout << "��ջ" << endl;
	myStack.popData();
	myStack.popData();
	myStack.printLinkStack();

	count = myStack.getCount();
	cout << "��ջԪ�ظ���:";
	cout << count << endl;


	myStack.destroyLinkStack();
	count = myStack.getCount();
	cout << "��ջԪ�ظ���:";
	cout << count << endl;

	system("pause");
	return 0;
}