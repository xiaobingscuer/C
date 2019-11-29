
/*
	���㷨�������ž��� 2���������� 7-6. 
	���⣺���� 
*/

#include <cstring>

#include <iostream>
#include <vector>
using namespace std;

const int nmax=9;
const int smax=100;
const int cmax=27;
int nn;//ʵ�ʽڵ��� 
int c[cmax]; //��¼��������Щ��㣬������ͽ���Ŷ�Ӧ 
int map[nmax];//����ź�ʵ�ʽ������Ӧ 
int G[nmax][nmax]; //����ͼ 
int Gn[nmax]; //����ÿ�������ڽ������� 
int a[nmax]; //��-�������� 
int vis[nmax];//�����ʱ�־ 
int opta[nmax];//���Ž�-�������� 
int k;//��-ͼ�Ĵ��� 

void print()
{
	for(int i=0;i<nn;i++){
		printf("%c ",map[opta[i]]+'A');
	}
	cout<<"-> ";
	cout<<k<<endl;
}
void dfs(int kt,int cur)
{
	if(cur==nn){
		k=kt;
		for(int i=0;i<nn;i++)opta[i]=a[i];
		return;
	}else{
		for(int i=0;i<nn;i++){
				int ktmp=kt;
				if(vis[i])continue;
//				if(cur>0)if(ktmp+Gn[a[cur-1]]>=k)continue;
				for(int j=0;j<cur;j++){
					if(G[i][a[j]]==1){
						if(ktmp<cur-j)ktmp=cur-j;
					}
				}
				if(ktmp<1)ktmp=1;
				if(ktmp<k){
						a[cur]=i;
						vis[i]=1;
						dfs(ktmp,cur+1);
						vis[i]=0;
			}
		}
	}
	return;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	while(1){
		memset(c,-1,sizeof(c));
		memset(map,-1,sizeof(map));
		memset(G,-1,sizeof(G));
		memset(Gn,0,sizeof(Gn));
//		memset(a,0,sizeof(a));
//		memset(vis,0,sizeof(vis));
		s.clear();
		nn=0;
		
		string stmp;
		getline(cin,s);
		if(s[0]=='#')break;
		for(int i=0;i<s.length();i++){
			if(!isblank(s[i]))stmp+=s[i];
		}
//		cout<<stmp<<endl;
		for(int i=0;i<stmp.length();i++){
			if(stmp[i]!=':'&&stmp[i]!=';')
				c[stmp[i]-'A']=1;
		}
		for(int i=0;i<cmax;i++){
			if(c[i]==1){
				c[i]=nn;
				map[nn++]=i;
			}
		}
//		cout<<nn<<endl;
		for(int i=0,offset=0,offset1=0;i<stmp.length();i++){
			offset=stmp[i]-'A';
			i+=2;
			while(stmp[i]!=';'&&i<stmp.length()){
				offset1=stmp[i++]-'A';
				if(G[c[offset]][c[offset1]]!=1){
					G[c[offset]][c[offset1]]=1;
					Gn[c[offset]]++;
				}
				if(G[c[offset1]][c[offset]]!=1){
					G[c[offset1]][c[offset]]=1;
					Gn[c[offset1]]++;
				}
			}
		}
		//�������
		k=nmax; 
		dfs(0,0);
		print();
//		for(int i=0;i<nn;i++){
//			printf("%c(%d): ",map[i]+'A',Gn[i]);
//			for(int j=0;j<nn;j++)
//			if(G[i][j]==1)printf("%c ",map[j]+'A');
//			cout<<endl;
//		}
//		cout<<endl;
		
	}
	cout<<endl;
	return 0;
}

