
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "stack.h"

stack createstack(void)
{
	stack s;
	s=malloc(sizeof(struct node));
	if(s==NULL)
		return NULL;
	s->X=INT_MIN;
	s->next=NULL;
	return s;
}

int isempty(stack S)
{
	// header
	// the second node is not exist
	return S->next==NULL;
}

int push(int X,stack S)
{
	ptr_to_node p;
	p=malloc(sizeof(struct node));
	if(p==NULL)
		return -1;
	p->X=X;
	p->next=S->next;
	S->next=p;
}

int pop(stack S)
{
	int top;
	if(!isempty(S))
	{
		ptr_to_node p;
		p=S->next;
		top=p->X;
		S->next=p->next;
		free(p);
		return top;
	}
	else
		return INT_MIN;
}

void makeempty(stack S)
{
	if(S!=NULL)
		while(!isempty(S))
		{
			ptr_to_node p;
			p=S->next;
			S->next=p->next;
			free(p);
		}
}

void printstackfromtop(stack S)
{
	printf("%s ", "top");
	ptr_to_node p;
	p=S->next;
	while(p != NULL)
	{
		printf("%d ", p->X);
		p=p->next;
	}
	printf("\n");
}

