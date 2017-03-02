
#ifndef _Tree_H
#define _Tree_H

struct node;
typedef struct node *ptr_to_node;
typedef ptr_to_node tree;
struct node
{
	char *str;
	tree firstchild;
	tree nextsibling;
};

tree createtree(void);
void pretraversal(tree T,int deepth);
void posttraversal(tree T,int deepth);
void leveltraversal(tree T,int deepth);
void freetree(tree T);
// X is an element,

#endif