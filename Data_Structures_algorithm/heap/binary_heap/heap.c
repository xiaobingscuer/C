
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "heap.h"

bheap createbheap(int maxelement)
{
	bheap bh;
	bh=(bheap)malloc(sizeof(struct bheapstruct));
	if(bh==NULL)
		return NULL;
	bh->array=(int *)malloc(sizeof(int)*(maxelement+1));
	if(bh->array==NULL)
		return NULL;
	bh->capacity=maxelement;
	bh->size=0;
	bh->array[0]=-1;
	return bh;
}

int isempty(bheap bh)
{
	return bh->size==0;
}

int isfull(bheap bh)
{
	return bh->size==bh->capacity;
}

void insertX(int X,bheap bh)
{
	int i;
	if(isfull(bh))
		return ;
	for(i=++bh->size;bh->array[i/2]>X;i/=2)
		bh->array[i]=bh->array[i/2];
	bh->array[i]=X;
}

int deleteX(bheap bh)
{
	if(isempty(bh))
		return -1;

	int i,child;
	int minx,lastx;
	minx=bh->array[1];
	lastx=bh->array[bh->size--];

	for(i=1;i*2<=bh->size;i=child)
	{
		child=i*2;
		if(child!=bh->size && bh->array[child+1]<bh->array[child])
			child++;
		if(lastx>bh->array[child])
			bh->array[i]=bh->array[child];
		else
			break;
	}
	bh->array[i]=lastx;

	return minx;
}

int findmin(bheap bh)
{
	return bh->array[1];
}