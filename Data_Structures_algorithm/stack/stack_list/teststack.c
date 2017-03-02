
#include <stdio.h>
#include "stack.h"

int main(int argc, char const *argv[])
{
	stack s;
	s=createstack();

	int i=0,state,x;
	while(i++<10)
	{
		state=push(i,s);
	}
	printstackfromtop(s);

	x=pop(s);
	printf("%d \n",x);
	printstackfromtop(s);

	makeempty(s);
	printstackfromtop(s);

	return 0;
}
