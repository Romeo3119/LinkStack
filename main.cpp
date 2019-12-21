#include "linklistStack.h"

int main()
{

	MyStack myStack;
	int count = 0;  //链栈元素的个数
	cout << "入栈" << endl;
	myStack.pushData(1);
	myStack.pushData(2);
	myStack.pushData(3);
	myStack.pushData(4);
	myStack.pushData(5);
	myStack.printLinkStack();

	cout << "出栈" << endl;
	myStack.popData();
	myStack.popData();
	myStack.printLinkStack();

	count = myStack.getCount();
	cout << "链栈元素个数:";
	cout << count << endl;


	myStack.destroyLinkStack();
	count = myStack.getCount();
	cout << "链栈元素个数:";
	cout << count << endl;

	system("pause");
	return 0;
}