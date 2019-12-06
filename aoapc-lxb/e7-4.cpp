
/*
	���㷨�������ž��� 2���������� 7-4. 
	���⣺������ 
	���� 
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int nmax=100;
int a[nmax];
int n;

void init(int n)
{
	for(int i=0;i<n;i++)a[i]=i+1;
}
void print(int n)
{
	for(int i=0;i<n;i++)cout<<a[i%n]<<" ";
	cout<<endl;
}
bool isprime(int n)
{
	int i,sqn;
	if(n==1)return true;
	if(n==2)return false;
	sqn=sqrt(n)+1;
	for(i=2;i<sqn;i++){
		if(n%i==0)return false;
	}
	return true;
}

//ֱ��������У���n=12ʱ�е�����n=16ʱֱ�Ӳ������ 
bool isprimering(int n)
{
	int s;
	for(int i=0;i<n;i++){
		s=a[i]+a[(i+1)%n];
		if(!isprime(s))return false;
	}
	return true;
}
void solve(int n)
{
	do{
		if(isprimering(n))
			print(n);
	}while(next_permutation(a+1,a+n));
}

//���ݷ�,��ֱ��������п���ˣ�����n=30���ܴ�ӡ��� 
int vis[nmax]; //���ʱ�־ 
void dfs(int cur,int n)
{
	if(cur==n && isprime(a[0]+a[n-1])){  //�ݹ�߽磬�Ҽ���׸������һ��֮��ҲΪ���� 
		print(n);
	}
	else 
	for(int i=2;i<=n;i++){
		if(!vis[i] && isprime(i+a[cur-1])){ //δ�����ʹ��Һ���һ����֮��Ϊ���� 
			a[cur]=i;  
			vis[i]=1; //���÷��ʱ�־ 
			dfs(cur+1,n);
			vis[i]=0; //������ʱ�־ 
		}
	}
}
int main(){
	
	while(cin>>n){
		//ֱ����� 
//		init(n);
//		solve(n);
		
		//���ݷ� 
		a[0]=1;
		dfs(1,n);
	}
	return 0;
}

