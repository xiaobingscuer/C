
#ifndef _Queue_H
#define _Queue_H

struct node;
typedef struct node *ptr_to_node;
typedef ptr_to_node position;
struct queueinfo;
typedef struct queueinfo *queue;
struct node
{
	int X;
	position next;
};
struct queueinfo
{
	int capacity;
	int size;
	position header;
	position tailer;
};

queue createqueue(int maxelement);
int isempty(queue Q);
int isfull(queue Q);
int enqueue(int X,queue Q);
int dequeue(queue Q);
void freequeue(queue Q);
void printqueue(queue Q);
// X is an element, Q is a list header
// P is a position in list 

#endif