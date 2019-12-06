
/*
	《算法竞赛入门经典 2》第七章例 7-4. 
	问题：素数环 
	回溯 
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

//直接穷举排列，当n=12时有点慢，n=16时直接不出结果 
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

//回溯法,比直接穷举排列快多了，就是n=30都能打印结果 
int vis[nmax]; //访问标志 
void dfs(int cur,int n)
{
	if(cur==n && isprime(a[0]+a[n-1])){  //递归边界，且检查首个和最后一个之和也为素数 
		print(n);
	}
	else 
	for(int i=2;i<=n;i++){
		if(!vis[i] && isprime(i+a[cur-1])){ //未被访问过且和上一个数之和为素数 
			a[cur]=i;  
			vis[i]=1; //设置访问标志 
			dfs(cur+1,n);
			vis[i]=0; //清除访问标志 
		}
	}
}
int main(){
	
	while(cin>>n){
		//直接穷举 
//		init(n);
//		solve(n);
		
		//回溯法 
		a[0]=1;
		dfs(1,n);
	}
	return 0;
}

