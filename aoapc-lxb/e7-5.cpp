
/*
	《算法竞赛入门经典 2》第七章例 7-5. 
	问题：困难的串 
*/
#include <iostream>
using namespace std;

const int nmax=100;
const char tab[nmax]={'A','B','C','D','E','F','G',
'H','I','J','K','L','M','N',
'O','P','Q','R','S','T','U',
'V','W','X','Y','Z'};
char a[nmax];
int n,L;
int cnt,one;
//判断串是否是困难串 
bool iskf(char* a,int l)
{
	int left,right,i,ok;
	for(i=2;i<=l;i+=2){
		left=l-i;
		right=l-i/2;
		ok=1;
		while(right<l){
			if(a[left++]!=a[right++]){
				ok=0;
				break;
			}
		}
		if(ok)return false;
	}
	return true;
}
//打印
void print(int cur) 
{
	for(int i=0;i<cur;i++)cout<<a[i];
	cout<<endl;
}
//可重复排列 
//带返回值的回溯，用于标记在这支递归过程中是否找到解，
//如果找到解，则直接向上返回，不会进行向右递归其他分支了 ，或者向下深入递归了 
//也就是说 解的条件 也是递归边界条件的一种 
int dfs(char* a,int l,int k,int cur)
{
	if(cnt++==k){ //边界条件——是否是解 
		print(cur);
		return 0;
	}else if(cur==k)return 1; //边界条件——解的长度 
	else
	for(int i=0;i<l;i++){
		a[cur]=tab[i];
		if(iskf(a,cur+1))if(!dfs(a,l,k,cur+1))return 0; //找到解直接向上返回 
	} 
	return 1; //此递归支路没找到解，返回1 
}

int main(){
	
	while(cin>>n>>L){
		cnt=0,one=0;
		dfs(a,L,n,0);
	}
	return 0;
}

