
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "tree.h"
#define max(a,b) (((a)>(b))?(a):(b));
// avl tree
int Height(Position P)
{
	if(P==NULL)
		return -1;
	else
		return P->Height;
}
Position SingleRotateWithLeft(Position k2)
{
	// k2 is the point of balance is distroied
	Position k1;
	k1=k2->Left;
	k2->Left=k1->Right;
	k1->Right=k2;
	// the node height is 
	// the max height between left child and right child 
	k2->Height=max(Height(k2->Left),Height(k2->Right))+1;
	k1->Height=max(Height(k1->Left),K2->Height)+1;

	return k1;
}
Position SingleRotateWithRight(Position k1)
{
	// k2 is the point of balance is distroied
	Position k2;
	k2=k1->Right;
	k1->Right=k2->Left;
	k2->Left=k1;
	// the node height is 
	// the max height between left child and right child 
	k1->Height=max(Height(k1->Right),Height(k1->Left))+1;
	k2->Height=max(Height(k2->Right),K1->Height)+1;

	return k2;
}
Position DoubleRotateWithLeft(Position k3)
{
	k3->Left=SingleRotateWithRight(k3->Left);
	return SingleRotateWithLeft(k3);
}
Position DoubleRotateWithRight(Position k3)
{
	k3->Right=SingleRotateWithLeft(k3->Right);
	return SingleRotateWithRight(k3);
}

AvlTree insertX(int X,AvlTree T)
{
	if(T==NULL)
	{
		T=(AvlTree)malloc(sizeof(struct AvlNode));
		if(T==NULL)
			return NULL;
		T->X=X;
		T->Left=NULL;
		T->Right=NULL;
		T->Height=0;
		return T;
	}
	else if(X<T->X)
	{
		T->left=insertX(X,T->Left);
		if(Height(T->Left)-Height(T->Right)==2)
			if(X<T->Left->X)
				SingleRotateWithLeft(T->Left);
			else
				DoubleRotateWithLeft(T->Left);
	}
	else if(X>T->X)
	{
		T->Right=insertX(X,T->Right);
		if(Height(T->Right)-Height(T->Left)==2)
			if(X>T->Left->X)
				SingleRotateWithRight(T->Left);
			else
				DoubleRotateWithRight(T->Left);
	}
	else;//nothing;
	T->Height=max(Height(T->Left),Height(T->Right))+1;
	
	return T;
}

tree findX(int X,tree T)
{
	if(T==NULL)
		return NULL;
	else if(X<T->X)
		findX(X,T->left);
	else if(X>T->X)
		findX(X,T->right);
	else
		return T;
}

tree findmin(tree T)
{
	if(T==NULL)
		return NULL;
	else if(T->left==NULL)
		return T;
	else
		return findmin(T->left);
}

tree findmax(tree T)
{
	if(T==NULL)
		return NULL;
	else if(T->right==NULL)
		return T;
	else
		return findmax(T->right);
}

tree deletX(int X,tree T)
{
	tree t;
	if(T==NULL)
		return NULL;
	else if(X<T->X)
		T->left=deletX(X,T->left);
	else if(X>T->X)
		T->right=deletX(X,T->right);
	else if(T->left && T->right)
	{
		t=findmin(T->right);
		T->X=t->X;
		T->right=deletX(T->X,T->right);
	}
	else
	{
		t=T;
		if(T->left==NULL)
			T=T->right;
		else if(T->right==NULL)
			T=T->left;
		free(t);
	}
	return T;
}

void pretraversal(tree T,int deepth,char c)
{
	if(T==NULL)
		return;
	int d=deepth;
	while(d-->0)
		printf("%s","  ");
	printf("%c:%d\n", c,T->X);
	pretraversal(T->left,deepth+1,'l');
	pretraversal(T->right,deepth+1,'r');
	return;
}
void posttraversal(tree T,int deepth,char c)
{
	if(T==NULL)
		return;
	posttraversal(T->left,deepth+1,'l');
	posttraversal(T->right,deepth+1,'r');
	int d=deepth;
	while(d-->0)
		printf("%s","  ");
	printf("%c:%d\n", c,T->X);
	return;
}

void midtraversal(tree T,int deepth,char c)
{
	if(T==NULL)
		return;
	// midtraversal actully get a sort 
	// such as min(l)->max(r)
	// or max(r)->min(l)

	midtraversal(T->left,deepth+1,'l');
	int d=deepth;
	while(d-->0)
		printf("%s","  ");
	printf("%c:%d\n", c,T->X);
	midtraversal(T->right,deepth+1,'r');

	// midtraversal(T->right,deepth+1,'l');
	// int d=deepth;
	// while(d-->0)
	// 	printf("%s","  ");
	// printf("%c:%d\n", c,T->X);
	// midtraversal(T->left,deepth+1,'r');
	return;
}

void freetree(tree T)
{
	if(T==NULL)
		return;
	freetree(T->left);
	freetree(T->right);
	free(T);
	return;
}

int height(tree T)
{
	// postorder traversal
	if(T==NULL)
		return -1;
	return 1+max(height(T->left),height(T->right));
}