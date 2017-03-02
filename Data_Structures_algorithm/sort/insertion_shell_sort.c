
#include <stdio.h>

// insertion sort O(N^2)
int insertion_sort(int *array,int n); 
// shell sort ci ;pO(N^2)
int shell_sort(int *array,int n);

int main(int argc, char const *argv[])
{
	int array[100];
	int i=0,n=10,data=0;
	while(i<n)
	{
		scanf("%d",&data);
		array[i++]=data; // initial state
	}

	insertion_sort(array,n); // insertion sort
	for(int i=0;i<n;i++)  // print result
		printf("%d ",array[i]);
	printf("\n");

	shell_sort(array,n); // shell sort
	for(int i=0;i<n;i++)  // print result
		printf("%d ",array[i]);
	printf("\n");
	return 0;
}

//insertion sort
int insertion_sort(int *array,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		int tmp=array[i];
		for(j=i;j>0 && tmp<array[j-1];j--)
			array[j]=array[j-1];
		array[j]=tmp;
	}
	return 0;
}
//shell sort
int shell_sort(int *array,int n)
{
	int i,j,increment;
	int data;
	for(increment=n/2;increment>0;increment/=2)
		for(i=increment;i<n;i++)
		{
			data=array[i];
			for(j=i;j>=increment && data<array[j-increment];\
				j-=increment)
				array[j]=array[j-increment];
			array[j]=data;
		}
}
