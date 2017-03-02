
#ifndef _Stack_H
#define _Stack_H

struct stackinfo;
typedef struct stackinfo *stack;
struct stackinfo
{
	int capacity;
	int top;
	int *array;
};
#define EMPTYELMENT -1
#define MINSIZE 5

stack createstack(int maxelment);
int isempty(stack S);
int isfull(stack S);
int push(int X,stack S);
int pop(stack S);
void makeempty(stack S);
void freestack(stack S);
void printstackfromtop(stack S);
// X is an element, S is a stack

#endif