
#include <stdio.h>
#include "queue.h"

int main(int argc, char const *argv[])
{
	queue q;
	q=createqueue(9);

	int i=1,state;
	state=0;
	while(i<=10 && !state)
	{
		state=enqueue(i,q);
		i++;
	}
	printqueue(q);

	i=1;
	state=dequeue(q);
	while(i<=11 && state!=-1)
	{
		printf(" %d ",state);
		state=dequeue(q);
		i++;
	}
	printqueue(q);

	i=1,state=0;
	while(i<=10 && !state)
	{
		state=enqueue(i,q);
		i++;
	}
	printqueue(q);

	return 0;
}