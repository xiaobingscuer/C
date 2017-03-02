
#ifndef _List_H
#define _List_H

struct node;
typedef struct node *ptr_to_node;
typedef ptr_to_node position;
typedef struct listinfo list;

struct node
{
	int X;
	position pre;
	position next;
};
struct listinfo
{
	position header;
	position tailer;
};

list creatlist(void);
int isempty(list L);
position find(int X,list L);
position insertXafterp(int X,list L,position P);
position insertXbeforep(int X,list L,position P);
int deleteX(int X,list L);
int modifyX(int X,int XN,list L);
list deletelist(list L);
void freelist(list L);
void printlist(list L);
void printlistfromtail(list L);
// X is an element, L is a list header
// P is a position in list,T is tail 

#endif