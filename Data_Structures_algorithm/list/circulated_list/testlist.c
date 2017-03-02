
#include <stdio.h>
#include "list.h"

int main(int argc, char const *argv[])
{
	list dlist;
	position p;
	dlist=creatlist();

	int i=0;
	while(i++<10)
	{
		p=insertXafterp(i,&dlist,dlist.header);
	}
	printf("%d\n",dlist.size);
	printlist(dlist);
	printlistfromtail(dlist);

	p=insertXbeforep(100,&dlist,dlist.header);
	printf("%d\n",dlist.size);
	printlist(dlist);
	printlistfromtail(dlist);

	modifyX(5,55,dlist);
	printlist(dlist);

	deleteX(55,&dlist);
	printf("%d\n",dlist.size);
	printlist(dlist);
	printlistfromtail(dlist);

	p=find(4,dlist);

	deletelist(&dlist);
	printf("%d\n",dlist.size);
	printlist(dlist);
	printlistfromtail(dlist);

	// freelist(dlist);
	// printlist(dlist);
	
	return 0;
}