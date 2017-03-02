
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "list.h"

list creatlist(void)
{
	list l={0,0};
	position h,t;
	h=malloc(sizeof(struct node));
	if (h==NULL)
		return l;
	h->X=INT_MIN;
	h->pre=h;
	h->next=h;
	l.header=h;
	return l;
}

int isempty(list L)
{
	// header
	// the second node is not exist
	return L.size==0;
}

position find(int X,list L)
{
	// header
	// find from second node
	position p=L.header->next;
	while(p!=L.header && p->X!=X)
	{
		p=p->next;
	}
	return p;
}

position insertXafterp(int X,list *L,position P)
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
	L->size++;
	return p;
}

position insertXbeforep(int X,list *L,position P)
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
	L->size++;
	return p;
}

int deleteX(int X,list *L)
{
	// header
	// delete X in list L
	position p;
	p=find(X,*L);
	if (p==L->header)
		return -1;
	p->pre->next=p->next;
	p->next->pre=p->pre;
	free(p);
	L->size--;
	return 0;
}

int modifyX(int X,int XN,list L)
{
	// header
	// modify:X=XN
	position p;
	p=find(X,L);
	if(p==NULL)
		return -1;
	p->X=XN;
}

list deletelist(list *L)
{
	position p,pnext;
	p=L->header->next;
	L->header->next=L->header;
	L->header->pre=L->header;
	L->size=0;
	while(p!=L->header)
	{
		pnext=p->next;
		free(p);
		p=pnext;
	}
	return *L;
}

void freelist(list *L)
{
	position p,pnext;
	p=L->header->next;
	while(p!=L->header)
	{
		pnext=p->next;
		free(p);
		p=pnext;
	}
	free(L->header);
	return ;
}

void printlist(list L)
{
	// printf("header->");
	position p=L.header->next;
	while(p!=L.header)
	{
		printf("%d",p->X);
		p=p->next;
		if(p!=L.header)
			printf("%s","->");
	}
	printf("\n");
	// printf("tailer\n");
}

void printlistfromtail(list L)
{
	// printf("header->");
	int circle=3*(L.size+1);
	position p=L.header->pre;
	while(p!=L.header)
	{
		printf("%d",p->X);
		p=p->pre;
		if(p!=L.header)
			printf("%s","->");
	}
	printf("\n");
	// printf("tailer\n");
}

