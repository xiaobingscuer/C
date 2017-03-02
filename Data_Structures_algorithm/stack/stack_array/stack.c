
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "stack.h"

stack createstack(int maxelment)
{
	stack s;
	if(maxelment<MINSIZE)
	{
		printf("%s\n","the element number of stack at least 5");
		return NULL;
	}
	s=malloc(sizeof(struct stackinfo));
	if(s==NULL)
	{
		printf("%s\n","no more memory!");
		return NULL;
	}
	s->array=malloc(sizeof(int)*maxelment);
	if(s->array==NULL)
	{
		printf("%s\n","no more memory!");
		return NULL;
	}
	s->capacity=maxelment;
	makeempty(s);
	return s;
}

int isempty(stack S)
{
	return S->top==EMPTYELMENT;
}

int isfull(stack S)
{
	return S->top == S->capacity-1;
}

int push(int X,stack S)
{
	if(!isfull(S))
		S->array[++S->top]=X;
	else
	{
		printf("%s\n","stack is full!");
		return -1;
	}
}

int pop(stack S)
{
	if(isempty(S))
	{
		printf("%s\n","stack is empty!");
		return -1;
	}
	int t=S->top;
	S->top--;
	return S->array[t];
}

void makeempty(stack S)
{
	S->top=EMPTYELMENT;
}
void freestack(stack S)
{
	if(S!=NULL)
	{
		free(S->array);
		free(S);
		printf("%s\n","free ths stack finished!");
	}
	else
	{
		printf("%s\n","no stack!");
	}
}

void printstackfromtop(stack S)
{
	if(S==NULL)
	{
		printf("%s\n","no stack!");
		return;
	}
	printf("%s ", "top");
	int t=S->top;
	while(t>=0)
	{
		printf("%d ", S->array[t]);
		t--;
	}
	printf("\n");
}

