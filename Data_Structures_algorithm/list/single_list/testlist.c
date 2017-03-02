
#include <stdio.h>
#include "list.h"

int main(int argc, char const *argv[])
{
	list l;
	position p;
	p=l=creatlist();

	int i=0;
	while(i++<10)
	{
		p=insertX(i,l,l);
	}
	printlist(l);

	modifyX(5,55,l);
	printlist(l);

	deleteX(10,l);
	printlist(l);

	p=find(5,l);

	deletelist(l);
	printlist(l);

	freelist(l);
	printlist(l);
	
	return 0;
}