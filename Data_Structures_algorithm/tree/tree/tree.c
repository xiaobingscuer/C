
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "tree.h"

tree createtree(void)
{
	tree root;
	tree usr;
	tree home;
	tree local;
	tree bin;
	tree lib;
	tree lxb;
	tree c;
	tree dl;
	tree rl;

	root=malloc(sizeof(struct node));
	usr=malloc(sizeof(struct node));
	home=malloc(sizeof(struct node));
	local=malloc(sizeof(struct node));
	bin=malloc(sizeof(struct node));
	lib=malloc(sizeof(struct node));
	lxb=malloc(sizeof(struct node));
	c=malloc(sizeof(struct node));
	dl=malloc(sizeof(struct node));
	rl=malloc(sizeof(struct node));

	if(root==NULL || usr==NULL || home==NULL || local==NULL\
		|| bin==NULL || lib==NULL || lxb==NULL\
		|| c==NULL || dl==NULL || rl==NULL)
		return NULL;
	root->str="root";
	root->firstchild=usr;
	root->nextsibling=NULL;

	usr->str="usr";
	usr->firstchild=local;
	usr->nextsibling=home;

	home->str="home";
	home->firstchild=lxb;
	home->nextsibling=NULL;

	local->str="local";
	local->firstchild=NULL;
	local->nextsibling=bin;

	bin->str="bin";
	bin->firstchild=NULL;
	bin->nextsibling=lib;

	lib->str="lib";
	lib->firstchild=NULL;
	lib->nextsibling=NULL;

	lxb->str="lxb";
	lxb->firstchild=c;
	lxb->nextsibling=NULL;

	c->str="c";
	c->firstchild=NULL;
	c->nextsibling=dl;

	dl->str="dl";
	dl->firstchild=NULL;
	dl->nextsibling=rl;

	rl->str="rl";
	rl->firstchild=NULL;
	rl->nextsibling=NULL;

	return root;
}

void pretraversal(tree T,int deepth)
{
	int d=deepth;
	while(d-->0)
		printf("%s","  ");
	printf("%s\n",T->str);
	if(T->firstchild!=NULL)
		pretraversal(T->firstchild,deepth+1);
	if(T->nextsibling!=NULL)
		pretraversal(T->nextsibling,deepth);
	return;
}

void posttraversal(tree T,int deepth)
{
	if(T->firstchild!=NULL)
		posttraversal(T->firstchild,deepth+1);

	int d=deepth;
	while(d-->0)
		printf("%s","  ");
	printf("%s\n",T->str);

	if(T->nextsibling!=NULL)
		posttraversal(T->nextsibling,deepth);
	
	return;
}

void leveltraversal(tree T,int deepth)
{
	if(T->firstchild!=NULL)
		leveltraversal(T->firstchild,deepth+1);
	if(T->nextsibling!=NULL)
		leveltraversal(T->nextsibling,deepth);
	
	int d=deepth;
	while(d-->0)
		printf("%s","  ");
	printf("%s\n",T->str);
	
	return;
}

void freetree(tree T)
{
	// posttraversal free
	if(T->firstchild!=NULL)
		free(T->firstchild);
	tree t=T;
	free(T);
	if(t->nextsibling!=NULL)
		free(t->nextsibling);

	return;
}