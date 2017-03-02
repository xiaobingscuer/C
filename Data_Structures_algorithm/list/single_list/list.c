
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "list.h"

list creatlist(void)
{
	list l;
	l=malloc(sizeof(struct node));
	l->X=INT_MIN;
	l->next=NULL;
	return l;
}

int isempty(list L)
{
	// header
	// the second node is not exist
	return L->next==NULL;
}

position find(int X,list L)
{
	// header
	// find from second node
	position p=L->next;
	while(p!=NULL && p->X!=X)
		p=p->next;
	return p;
}

position findprenode(int X,list L)
{
	// header
	// find from second node
	position p=L;
	while(p->next!=NULL && p->next->X!=X)
		p=p->next;
	return p;
}

position insertX(int X,list L,position P)
{
	// header
	// insert X after position p
	position p;
	p=malloc(sizeof(struct node));
	if (p==NULL)
		return p;
	p->X=X;
	p->next=P->next;
	P->next=p;
	return p;
}

int deleteX(int X,list L)
{
	// header
	// delete X in list L
	position p,pre;
	pre=findprenode(X,L);
	p=pre->next;
	if(p==NULL)
		return -1;
	pre->next=p->next;
	free(p);
	return 0;
}

int modifyX(int X,int XN,list l)
{
	// header
	// modify:X=XN
	position p;
	p=find(X,l);
	if(p==NULL)
		return -1;
	p->X=XN;
}

list deletelist(list L)
{
	// header
	position p,pnext;
	p=L->next;
	L->next=NULL;
	// free(L); // free header
	while(p!=NULL)
	{
		pnext=p->next;
		free(p);
		p=pnext;
	}
	return L;
}

void freelist(list L)
{
	// header
	position p,pnext;
	p=L->next;
	free(L); // free header
	while(p!=NULL)
	{
		pnext=p->next;
		free(p);
		p=pnext;
	}
	return ;
}
void printlist(list L)
{
	// header
	printf("header->");
	position p=L->next;
	while(p!=NULL)
	{
		printf("%d->",p->X);
		p=p->next;
	}

	// no header
	// position p=L;
	// while(1)
	// {
	// 	printf("%d->",p->X);
	// 	p=p->next;
	// 	if(p==NULL)
	// 		break;
	// }

	printf("null\n");
}