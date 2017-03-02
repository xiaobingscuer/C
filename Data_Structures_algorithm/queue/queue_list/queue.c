
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "queue.h"

queue createqueue(int maxelement)
{
	queue q;
	if(maxelement<0)
		return NULL;
	q=malloc(sizeof(struct queueinfo));
	if(q==NULL)
		return NULL;
	position h;
	h=malloc(sizeof(struct node));
	if (h==NULL)
		return NULL;
	h->X=INT_MIN;
	h->next=NULL;
	q->capacity=maxelement;
	q->size=0;
	q->header=h;
	q->tailer=h;
	printf("%s\n","create queue finised!");
	return q;
}

int isempty(queue Q)
{
	// header
	// the second node is not exist
	if(Q->header->next==NULL)
		printf("%s\n","queue is empty!");
	return Q->header->next==NULL;
}

int isfull(queue Q)
{
	if(Q->size==Q->capacity)
		printf("%s\n","queue is full!");
	return Q->size==Q->capacity;
}

int enqueue(int X,queue Q)
{
	position p;
	if(isfull(Q))
		return -1;
	p=malloc(sizeof(struct node));
	if(p==NULL)
		return -1;
	p->X=X;
	p->next=Q->tailer->next;
	Q->tailer->next=p;
	Q->tailer=p;
	Q->size++;
	return 0;
}

int dequeue(queue Q)
{
	int x;
	position p;
	if(isempty(Q))
		return -1;
	p=Q->header->next;
	x=p->X;
	Q->header->next=p->next;
	free(p);
	Q->size--;
	return x;
}

void freequeue(queue Q)
{
	position p,pnext;
	if(Q!=NULL)
	{
		p=pnext=Q->header->next;
		while(p!=NULL)
		{
			pnext=p->next;
			free(p);
			p=pnext;
		}
		free(Q->header);
	}
}

void printqueue(queue Q)
{
	if(isempty(Q))
		return ;
	int x;
	position p;
	p=Q->header->next;
	while(p!=NULL)
	{
		printf("%d ",p->X);
		p=p->next;
	}
	printf("finised print!\n");
}

