
/*
	���㷨�������ž��� 2���������� 7-5. 
	���⣺���ѵĴ� 
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
//�жϴ��Ƿ������Ѵ� 
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
//��ӡ
void print(int cur) 
{
	for(int i=0;i<cur;i++)cout<<a[i];
	cout<<endl;
}
//���ظ����� 
//������ֵ�Ļ��ݣ����ڱ������֧�ݹ�������Ƿ��ҵ��⣬
//����ҵ��⣬��ֱ�����Ϸ��أ�����������ҵݹ�������֧�� ��������������ݹ��� 
//Ҳ����˵ ������� Ҳ�ǵݹ�߽�������һ�� 
int dfs(char* a,int l,int k,int cur)
{
	if(cnt++==k){ //�߽����������Ƿ��ǽ� 
		print(cur);
		return 0;
	}else if(cur==k)return 1; //�߽�����������ĳ��� 
	else
	for(int i=0;i<l;i++){
		a[cur]=tab[i];
		if(iskf(a,cur+1))if(!dfs(a,l,k,cur+1))return 0; //�ҵ���ֱ�����Ϸ��� 
	} 
	return 1; //�˵ݹ�֧·û�ҵ��⣬����1 
}

int main(){
	
	while(cin>>n>>L){
		cnt=0,one=0;
		dfs(a,L,n,0);
	}
	return 0;
}

