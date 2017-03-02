
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "list.h"

list creatlist(void)
{
	list l={0,0};
	position h,t;
	h=malloc(sizeof(struct node));
	t=malloc(sizeof(struct node));
	if (h==NULL || t==NULL)
		return l;
	h->X=t->X=INT_MIN;
	h->pre=NULL;
	h->next=t;
	t->pre=h;
	t->next=NULL;
	l.header=h;
	l.tailer=t;
	return l;
}

int isempty(list L)
{
	// header
	// the second node is not exist
	return L.header->next==L.tailer;
}

position find(int X,list L)
{
	// header
	// find from second node
	position p=L.header;
	while(p!=L.tailer && p->X!=X)
		p=p->next;
	return p;
}

position insertXafterp(int X,list L,position P)
{
	// header
	// insert X after position p
	position p;
	p=malloc(sizeof(struct node));
	if (p==NULL)
		return p;
	p->X=X;
	p->pre=P;
	p->next=P->next;
	P->next->pre=p;
	P->next=p;
	return p;
}

position insertXbeforep(int X,list L,position P)
{
	// header
	// insert X before position p
	position p;
	p=malloc(sizeof(struct node));
	if (p==NULL)
		return p;
	p->X=X;
	p->next=P;
	p->pre=P->pre;
	P->pre->next=p;
	P->pre=p;
	return p;
}

int deleteX(int X,list L)
{
	// header
	// delete X in list L
	position p;
	p=find(X,L);
	if(p==L.tailer)
		return -1;
	p->pre->next=p->next;
	p->next->pre=p->pre;
	free(p);
	return 0;
}

int modifyX(int X,int XN,list L)
{
	// header
	// modify:X=XN
	position p;
	p=find(X,L);
	if(p==L.tailer)
		return -1;
	p->X=XN;
}

list deletelist(list L)
{
	position p,pnext;
	p=L.header->next;
	L.header->next=L.tailer;
	L.tailer->pre=L.header;
	while(p!=L.tailer)
	{
		pnext=p->next;
		free(p);
		p=pnext;
	}
	return L;
}

void freelist(list L)
{
	position p,pnext;
	p=L.header->next;
	free(L.header);
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
	printf("header->");
	position p=L.header->next;
	while(p!=L.tailer)
	{
		printf("%d->",p->X);
		p=p->next;
	}
	printf("tailer\n");
}

void printlistfromtail(list L)
{
	printf("tailer->");
	position p=L.tailer->pre;
	while(p!=L.header)
	{
		printf("%d->",p->X);
		p=p->pre;
	}
	printf("header\n");
}

