
#ifndef _Queue_H
#define _Queue_H

struct queueinfo;
typedef struct queueinfo *queue;
struct queueinfo
{
	int capacity;
	int size;
	int *array;
	int header;
	int tailer;
};

queue createqueue(int maxelement);
int isempty(queue Q);
int isfull(queue Q);
int enqueue(int X,queue Q);
int dequeue(queue Q);
void freequeue(queue Q);
void printqueue(queue Q);
// X is an element, 

#endif