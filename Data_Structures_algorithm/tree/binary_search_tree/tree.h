
#ifndef _Tree_H
#define _Tree_H
// binary search tree
struct node;
typedef struct node *ptr_to_node;
typedef ptr_to_node tree;
struct node
{
	int X;
	tree left;
	tree right;
};

#define max(a,b) ((a)>=(b)?(a):(b));
tree makeempty(tree T);
void freetree(tree T);
tree findX(int X,tree T);
tree findmin(tree T);
tree findmax(tree T);
int modify(int XN,tree T);
tree insertX(int X,tree T);
tree deletX(int X,tree T);
void pretraversal(tree T,int deepth,char c);
void posttraversal(tree T,int deepth,char c);
void midtraversal(tree T,int deepth,char c);
int height(tree T);

// X is an element,

#endif