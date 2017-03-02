
#include <stdio.h>
#include "queue.h"

int main(int argc, char const *argv[])
{
	queue q;
	q=createqueue(5);

	int state=0;
	state=enqueue(1,q);
	state=enqueue(2,q);
	state=enqueue(3,q);
	state=enqueue(4,q);
	
	state=dequeue(q);
	state=dequeue(q);

	state=enqueue(5,q);
	state=enqueue(6,q);
	state=enqueue(7,q);

	state=dequeue(q);
	state=dequeue(q);
	state=dequeue(q);
	state=dequeue(q);
	state=dequeue(q);

	printf("header: %d\n",q->header);
	printf("tailer: %d\n",q->tailer);
	printqueue(q);

	return 0;
}