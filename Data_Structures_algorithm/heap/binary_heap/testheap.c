
#include <stdio.h>
#include "heap.h"

int main(int argc, char const *argv[])
{
	int array[10]={0};
	int x,num=6;
	bheap bh=createbheap(6);
	printf("%s\n","insertX into heap:");
	while(num--)
	{
		scanf("%d",&x);
		insertX(x,bh);
	}
	printf("%s\n","deleteX for sort from min to max:");
	for(int i=0;i<6;i++)
	{
		printf("%d\n",deleteX(bh));
	}
	return 0;
}