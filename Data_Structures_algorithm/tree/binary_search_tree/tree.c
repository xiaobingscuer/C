
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "tree.h"

// binary search tree
tree insertX(int X,tree T)
{
	if(T==NULL)
	{
		T=(tree)malloc(sizeof(struct node));
		if(T==NULL)
			return NULL;
		T->X=X;
		T->left=NULL;
		T->right=NULL;
		return T;
	}
	else if(X<T->X)
		T->left=insertX(X,T->left);
	else if(X>T->X)
		T->right=insertX(X,T->right);
	else;//nothing;
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