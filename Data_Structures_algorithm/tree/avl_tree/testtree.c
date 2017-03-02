
#include <stdio.h>
#include "tree.h"

int main(int argc, char const *argv[])
{
	tree root=NULL;
	printf("%p\n",root );

	int x,num=6;
	while(num--)
	{
		scanf("%d",&x);
		root=insertX(x,root);
	}
	printf("%p\n",root );

	printf("%s\n","preorder traversal:");
	pretraversal(root,0,'/');
	// printf("%s\n","postorder traversal:");
	// posttraversal(root,0,'/');
	// printf("%s\n","midorder traversal:");
	// midtraversal(root,0,'/');

	// int h=height(root);
	printf("the height of the tree is %d\n",(*height)(root));
	deletX(6,root);printf("\n");
	pretraversal(root,0,'/');

	freetree(root);
	printf("%p\n", root);

	return 0;
}