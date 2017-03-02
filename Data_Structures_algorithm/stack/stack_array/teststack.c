
#include <stdio.h>
#include "stack.h"

int main(int argc, char const *argv[])
{
	stack s;
	s=createstack(15);
	if(s==NULL)
	{
		printf("%s\n","stack is not exist!");
		return -1;
	}
	int i=0,state,x;
	while(i++<10)
	{
		state=push(i,s);
	}
	printstackfromtop(s);

	while(--i>=1)
	{
		x=pop(s);
		printf("%d \n",x);
	}
	printstackfromtop(s);

	makeempty(s);
	printstackfromtop(s);

	freestack(s);

	return 0;
}
