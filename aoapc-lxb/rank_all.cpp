
/*
	Name: 按字典序进行全排列 
	Copyright: 
	Author: 
	Date: 12/11/17 17:16
	Description: 按字典序进行全排列 ，比如从12345,...,54321s 
*/

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
/*
											
*/ 
//对初始序列为1234...n进行全排列，这些序列无重复元素 
void rank_all(int n,int* A,int cur)
{
	//递归边界 
	if(cur==n)
	{
		for(int i=0;i<n;i++)cout<<A[i]<<" ";
		cout<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			int ok=1;
			for(int j=0;j<cur;j++)
			{
				if(A[j]==i)ok=0; 
			}
			if(ok)
			{
				A[cur]=i;
				rank_all(n,A,cur+1); 
			}
		}
	}
}

//如果对输入的数组P进行按字典序进行全排列
// 首先将P按字典序进行排序后再调用此全排列的方法
// 只需将A[j]==i改为A[j]==P[i]
// 以及将A[cur]=i改为A[cur]=P[i] 
void rank_all1(int n,int* P,int* A,int cur)
{
	//递归边界 
	if(cur==n)
	{
		for(int i=0;i<n;i++)cout<<A[i]<<" ";
		cout<<endl;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			int ok=1;
			for(int j=0;j<cur;j++)
			{
				if(A[j]==P[i])ok=0; 
			}
			if(ok)
			{
				A[cur]=P[i];
				rank_all1(n,P,A,cur+1); 
			}
		}
	}
}

// 这样就能对P进行全排列，但是这要求P不能有相同的元素，
// 因为此方法的条件判断只对不同元素才会进行递归排列
// 解决P中有重复元的排列问题，可以比较已排列的元素A[0...cur]中P[i]的个数c1
// 与 P[0...n]中P[i]元素的个数c2，如果c1<c2,则条件判断为真 
// 这样即使元素有重复也可以全部排列出来，但是对于 {1,1,1}序列
// 实际排列结果为1个序列，就是其本身 
// 但是会把以每个元素开头所有结果都排列出来，总共就会出现27个{1,1,1}序列 
// 这时可以利用P以按字典序排过序，这样相同的元素会相邻，
// 这时只需判断对与上一个不同的元素开始进行排列 
// 因此对P中元素按某种序标准排序，将重复元素放到了一起，是关键的一步 
void rank_all2(int n,int* P,int* A,int cur)
{
	//递归边界 
	if(cur==n)
	{
		for(int i=0;i<n;i++)cout<<A[i]<<" ";
		cout<<endl;
	}
	else
	{
		for(int i=0;i<n;i++)
		if(!i||P[i]!=P[i-1]) 
		{
			int c1=0,c2=0; 
			for(int j=0;j<cur;j++)if(A[j]==P[i])c1++;
			for(int j=0;j<n;j++)if(P[j]==P[i])c2++;
			if(c1<c2)
			{
				A[cur]=P[i];
				rank_all2(n,P,A,cur+1); 
			}
		}
	}
}

// 使用库函数下一个排列next_permutation()来生程下一个排列，重复调用
// 就可以全部举出来所有的排列了
// next_permutation()也适用于有重复元素的排列 
void rank_all3(int *A,int n)
{
	do{
		for(int i=0;i<n;i++)cout<<A[i]<<" ";
		cout<<endl;
	}while(next_permutation(A,A+n));
}

int main(){
	int n=3;
	int A[n];
	int P[]={1,1,1};
	memset(A,0,sizeof(A));
//	rank_all2(n,P,A,0);
	rank_all3(P,3);
	return 0;
}

