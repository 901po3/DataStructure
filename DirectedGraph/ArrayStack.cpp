#include"ArrayStack.h"

ArrayStack::ArrayStack()
{
	Top = -1;
}

ArrayStack::~ArrayStack()
{

}

void ArrayStack::Push(myType data)
{
	if(Top>MAX)
		return;
	Stack[++Top] = data;
}

myType ArrayStack::Pop()
{
	if(IsStackEmpty())
		return 0;
	return Stack[Top--];
}

bool ArrayStack::IsStackEmpty()
{
	if(Top == -1)
		return true;
	else false;
}
