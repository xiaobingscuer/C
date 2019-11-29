
/*
	Name: ���ֵ������ȫ���� 
	Copyright: 
	Author: 
	Date: 12/11/17 17:16
	Description: ���ֵ������ȫ���� �������12345,...,54321s 
*/

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
/*
											
*/ 
//�Գ�ʼ����Ϊ1234...n����ȫ���У���Щ�������ظ�Ԫ�� 
void rank_all(int n,int* A,int cur)
{
	//�ݹ�߽� 
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

//��������������P���а��ֵ������ȫ����
// ���Ƚ�P���ֵ������������ٵ��ô�ȫ���еķ���
// ֻ�轫A[j]==i��ΪA[j]==P[i]
// �Լ���A[cur]=i��ΪA[cur]=P[i] 
void rank_all1(int n,int* P,int* A,int cur)
{
	//�ݹ�߽� 
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

// �������ܶ�P����ȫ���У�������Ҫ��P��������ͬ��Ԫ�أ�
// ��Ϊ�˷����������ж�ֻ�Բ�ͬԪ�زŻ���еݹ�����
// ���P�����ظ�Ԫ���������⣬���ԱȽ������е�Ԫ��A[0...cur]��P[i]�ĸ���c1
// �� P[0...n]��P[i]Ԫ�صĸ���c2�����c1<c2,�������ж�Ϊ�� 
// ������ʹԪ�����ظ�Ҳ����ȫ�����г��������Ƕ��� {1,1,1}����
// ʵ�����н��Ϊ1�����У������䱾�� 
// ���ǻ����ÿ��Ԫ�ؿ�ͷ���н�������г������ܹ��ͻ����27��{1,1,1}���� 
// ��ʱ��������P�԰��ֵ����Ź���������ͬ��Ԫ�ػ����ڣ�
// ��ʱֻ���ж϶�����һ����ͬ��Ԫ�ؿ�ʼ�������� 
// ��˶�P��Ԫ�ذ�ĳ�����׼���򣬽��ظ�Ԫ�طŵ���һ���ǹؼ���һ�� 
void rank_all2(int n,int* P,int* A,int cur)
{
	//�ݹ�߽� 
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

// ʹ�ÿ⺯����һ������next_permutation()��������һ�����У��ظ�����
// �Ϳ���ȫ���ٳ������е�������
// next_permutation()Ҳ���������ظ�Ԫ�ص����� 
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

