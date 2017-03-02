
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "queue.h"

queue createqueue(int maxelement)
{
	queue q;
	q=malloc(sizeof(struct queueinfo));
	if(q==NULL)
		return NULL;
	q->capacity=maxelement;
	q->size=0;
	q->array=malloc(maxelement*sizeof(int));
	if(q->array==NULL){
		printf("%s\n","is null");
		return NULL;
	}
	q->header=1;
	q->tailer=0;
	return q;
}

int isempty(queue Q)
{
	// header
	// the second node is not exist
	if(Q->size==0)
		printf("%s\n","queue is empty!");
	return Q->size==0;
}

int isfull(queue Q)
{
	if(Q->size==Q->capacity)
		printf("%s\n","queue is full!");
	return Q->size==Q->capacity;
}

int enqueue(int X,queue Q)
{
	if(isfull(Q))
		return -1;
	Q->size++;
	Q->tailer++;
	if(Q->tailer==Q->capacity)
		Q->tailer=0;
	Q->array[Q->tailer]=X;
	return 0;
}

int dequeue(queue Q)
{
	if(isempty(Q))
		return -1;
	int x;
	x=Q->array[Q->header];
	Q->size--;
	Q->header++;
	if(Q->header==Q->capacity)
		Q->header=0;
	return x;
}

void freequeue(queue Q)
{
	if(Q!=NULL)
	{
		free(Q->array);
		free(Q);
	}
}

void printqueue(queue Q)
{
	int h,size=Q->size;
	h=Q->header;
	if(isempty(Q))
		return;
	while(size--)
	{
		if(h==Q->capacity)
			h=0;
		printf("%d ", Q->array[h++]);
	}
	printf("\n");
}

