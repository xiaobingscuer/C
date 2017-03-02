
#ifndef _AVLTree_H
#define _AVLTree_H
// AVL tree
struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
struct  AvlNode
{
	int X;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

AvlTree makeempty(AvlTree T);
Position find(int X,AvlTree T);
Position findmin(AvlTree T);
Position findmax(AvlTree T);
AvlTree insertX(AvlTree T,int X);
AvlTree deleteX(AvlTree T,int X);
void free(AvlTree T);
int Height(Position P);
Position SingleRotateWithLeft(Position k2);
Position SingleRotateWithRight(Position k2);
Position DoubleRotateWithLeft(Position k3);
Position DoubleRotateWithRight(Position k3);
// X is an element,

#endif