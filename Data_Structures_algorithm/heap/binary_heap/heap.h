
#ifndef _Binary_Heap_H
#define _Binary_Heap_H

struct bheapstruct;
typedef struct bheapstruct *bheap;
struct bheapstruct
{
	int capacity;
	int size;
	int *array;
};

bheap createbheap(int maxelement);
void freebheap(bheap bh);
int isempty(bheap bh);
int isfull(bheap bh);
void insertX(int X,bheap bh);
int deleteX(bheap bh);
int findmin(bheap bh);

// X is an elemesnt,

#endif
