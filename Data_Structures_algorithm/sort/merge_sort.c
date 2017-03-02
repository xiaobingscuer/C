
#include <stdio.h>
#include <stdlib.h>

// merge sort O(NlogN)
int merge_sort(int *array,int n); // main
void Msort(int *array,int *tmparray,int left,int right);//digui
void Merge(int *array,int *tmparray,int lpos,int rpos,int rightend);//merge

int main(int argc, char const *argv[])
{
	int array[100];
	int i=0,n=10,data=0;
	while(i<n)
	{
		scanf("%d",&data);
		array[i++]=data; // initial state
	}

	merge_sort(array,n); // merge sort
	for(int i=0;i<n;i++)  // print result
		printf("%d ",array[i]);
	printf("\n");

	return 0;
}

// merge sort O(NlogN)
int merge_sort(int *array,int n)
{
	int *tmparray;
	tmparray=malloc(n*sizeof(int));
	if(tmparray==NULL)
		return -1;
	Msort(array,tmparray,0,n-1);
	free(tmparray);
	return 0;
}
void Msort(int *array,int *tmparray,int left,int right)
{
	int center;
	if(left<right)
	{
		center=(left+right)/2;
		Msort(array,tmparray,left,center);
		Msort(array,tmparray,center+1,right);
		Merge(array,tmparray,left,center+1,right);
	}
}
void Merge(int *array,int *tmparray,int lpos,int rpos,int rightend)
{
	int i,leftend,numelement,tmppos;
	leftend=rpos-1;
	tmppos=lpos;
	numelement=rightend-lpos+1;
	// main loop
	while(lpos<=leftend && rpos<=rightend)
		if(array[lpos]<=array[rpos])
			tmparray[tmppos++]=array[lpos++];
		else
			tmparray[tmppos++]=array[rpos++];
	while(lpos<=leftend)
		tmparray[tmppos++]=array[lpos++];
	while(rpos<=rightend)
		tmparray[tmppos++]=array[rpos++];
	// copy tmparray back
	for(i=0;i<numelement;i++,rightend--)
		array[rightend]=tmparray[rightend];
}