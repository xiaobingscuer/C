
#ifndef _Stack_H
#define _Stack_H

struct node;
typedef struct node *ptr_to_node;
typedef ptr_to_node stack;
struct node
{
	int X;
	ptr_to_node next;
};

stack createstack(void);
int isempty(stack S);
int push(int X,stack S);
int pop(stack S);
void makeempty(stack S);
void printstackfromtop(stack S);
// X is an element, S is a stack

#endif