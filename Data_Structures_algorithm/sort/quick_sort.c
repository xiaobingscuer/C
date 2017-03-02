
#include <stdio.h>
#include <stdlib.h>

#define cutoff (3);
// quick sort O(NlogN)
void quick_sort(int *array,int n);
int median3(int *array,int left,int right);
void Qsort(int *array,int left,int right);

int main(int argc, char const *argv[])
{
	int array[100];
	int i=0,n=10,data=0;
	while(i<n)
	{
		scanf("%d",&data);
		array[i++]=data; // initial state
	}

	quick_sort(array,n); // quick sort
	for(int i=0;i<n;i++)  // print result
		printf("%d ",array[i]);
	printf("\n");

	return 0;
}

// quick sort O(NlogN)
void quick_sort(int *array,int n)
{
	Qsort(array,0,n-1);
}
void swap(int *pa,int *pb)
{
	int tmp;
	tmp=*pa;
	*pa=*pb;
	*pb=tmp;
}
int median3(int *array,int left,int right)
{
	int center=(left+right)/2;
	if (array[left]>array[center])
		swap(&array[left],&array[center]);
	if(array[center]>array[right])
		swap(&array[center],&array[right]);
	if (array[left]>array[center])
		swap(&array[left],&array[center]);
	//
	swap(&array[center],&array[right-1]);
	return array[right-1];
}
void Qsort(int *array,int left,int right)
{
	if(left<right) // no or one element ->return;
	{
		// small array with insertion sort
		// if(left+cutoff<=right)
		// {
			int i,j;
			int pivot;
			pivot=median3(array,left,right);
			// printf("%d\n",pivot );
			i=left,j=right-1;
			while(1)
			{
				while(array[++i]<pivot);
				while(array[--j]>pivot);
				if(i<j)
					swap(&array[i],&array[j]);
				else
					break;
			}
			if(j!=right-2) // if j=right-2,it's two elements
				swap(&array[right-1],&array[i]);
			//becase median3 has sort the two ,so don't also swap
			Qsort(array,left,i-1);
			Qsort(array,i+1,right);
		// }
		// else
		// 	insertion_sort(array+left,right-left-1);
	}
	else
		return;
}
