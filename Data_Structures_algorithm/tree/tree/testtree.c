
#include <stdio.h>
#include "tree.h"

int main(int argc, char const *argv[])
{
	tree root;
	root=createtree();

	printf("%s\n","preorder traversal:");
	pretraversal(root,0);

	printf("%s\n","postorder traversal:");
	posttraversal(root,0);

	printf("%s\n","levelorder traversal:");
	leveltraversal(root,0);
	
	printf("%s\n", root->str);
	freetree(root);
	printf("%s\n", root->str);

	return 0;
}