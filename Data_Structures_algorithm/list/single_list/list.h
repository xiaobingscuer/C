
#ifndef _List_H
#define _List_H

struct node;
typedef struct node *ptr_to_node;
typedef ptr_to_node list;
typedef ptr_to_node position;
struct node
{
	int X;
	position next;
};

list creatlist(void);
int isempty(list L);
position find(int X,list L);
position findprenode(int X,list L);
position insertX(int X,list L,position P);
int deleteX(int X,list L);
int modifyX(int X,int XN,list L);
list deletelist(list L);
void freelist(list L);
void printlist(list L);
// X is an element, L is a list,P is a position in list

#endif