
/*
	���㷨�������ž��� 2���������� 7-4-1. 
	����1���˻ʺ����� 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=8;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
int map[maxn][maxn];
int cnt=0;
//��ʼ�� 
void init()
{
	for(int r=0;r<maxn;r++)
	for(int c=0;c<maxn;c++)
	map[r][c]=0;
}
//��ӡ�� 
void print()
{
	for(int r=0;r<maxn;r++){
		for(int c=0;c<maxn;c++)
			if(map[r][c]>0)cout<<map[r][c]<<" ";
			else cout<<0<<" ";
		cout<<endl;
	}
	cout<<endl; 
}
//ģ�⹥����Χ 
void hostile(int x,int y)
{
	int nx,ny;
	//up
	nx=x;ny=y;
	while(1){
		nx+=dx[0];
		if(nx>=0&&nx<maxn&&ny>=0&&ny<maxn)
			map[nx][ny]-=1;
		else break;
	}
	//up-right
	nx=x;ny=y;
	while(1){
		nx+=dx[0];
		ny+=dy[1];
		if(nx>=0&&nx<maxn&&ny>=0&&ny<maxn)
			map[nx][ny]-=1;
		else break;
	}
	//right
	nx=x;ny=y;
	while(1){
		ny+=dy[1];
		if(nx>=0&&nx<maxn&&ny>=0&&ny<maxn)
			map[nx][ny]-=1;
		else break;
	}
	//right-down
	nx=x;ny=y;
	while(1){
		nx+=dx[2];
		ny+=dy[1];
		if(nx>=0&&nx<maxn&&ny>=0&&ny<maxn)
			map[nx][ny]-=1;
		else break;
	}
	//down
	nx=x;ny=y;
	while(1){
		nx+=dx[2];
		if(nx>=0&&nx<maxn&&ny>=0&&ny<maxn)
			map[nx][ny]-=1;
		else break;
	}
	//left-down
	nx=x;ny=y;
	while(1){
		nx+=dx[2];
		ny+=dy[3];
		if(nx>=0&&nx<maxn&&ny>=0&&ny<maxn)
			map[nx][ny]-=1;
		else break;
	}
	//left
	nx=x;ny=y;
	while(1){
		ny+=dy[3];
		if(nx>=0&&nx<maxn&&ny>=0&&ny<maxn)
			map[nx][ny]-=1;
		else break;
	}
	//left-up
	nx=x;ny=y;
	while(1){
		nx+=dx[0];
		ny+=dy[3];
		if(nx>=0&&nx<maxn&&ny>=0&&ny<maxn)
			map[nx][ny]-=1;
		else break;
	}
}
//����ģ����� 
void undo(int x,int y)
{
	int nx,ny;
	//up
	nx=x;ny=y;
	while(1){
		nx+=dx[0];
		if(nx>=0&&nx<maxn&&ny>=0&&ny<maxn)
			map[nx][ny]+=1;
		else break;
	}
	//up-right
	nx=x;ny=y;
	while(1){
		nx+=dx[0];
		ny+=dy[1];
		if(nx>=0&&nx<maxn&&ny>=0&&ny<maxn)
			map[nx][ny]+=1;
		else break;
	}
	//right
	nx=x;ny=y;
	while(1){
		ny+=dy[1];
		if(nx>=0&&nx<maxn&&ny>=0&&ny<maxn)
			map[nx][ny]+=1;
		else break;
	}
	//right-down
	nx=x;ny=y;
	while(1){
		nx+=dx[2];
		ny+=dy[1];
		if(nx>=0&&nx<maxn&&ny>=0&&ny<maxn)
			map[nx][ny]+=1;
		else break;
	}
	//down
	nx=x;ny=y;
	while(1){
		nx+=dx[2];
		if(nx>=0&&nx<maxn&&ny>=0&&ny<maxn)
			map[nx][ny]+=1;
		else break;
	}
	//left-down
	nx=x;ny=y;
	while(1){
		nx+=dx[2];
		ny+=dy[3];
		if(nx>=0&&nx<maxn&&ny>=0&&ny<maxn)
			map[nx][ny]+=1;
		else break;
	}
	//left
	nx=x;ny=y;
	while(1){
		ny+=dy[3];
		if(nx>=0&&nx<maxn&&ny>=0&&ny<maxn)
			map[nx][ny]+=1;
		else break;
	}
	//left-up
	nx=x;ny=y;
	while(1){
		nx+=dx[0];
		ny+=dy[3];
		if(nx>=0&&nx<maxn&&ny>=0&&ny<maxn)
			map[nx][ny]+=1;
		else break;
	}
}
//�����⣬�����ջ� 
//�Լ���ģ�ö�ٵ���maxn����ͬ�Ļʺ����η�������໥�����ķ�����
//Ч����ѡ����е���Ϻ������У��� C(maxn*maxn,maxn)*A(maxn,maxn)
//���Ӷȱȵ�������Ϻ����е�ʱ�临�Ӷȶ��� 
//������������ػ����һ�� �����ڴ���ͷ��ڴ�ĵݹ鷽ʽ
//����ʹ���˸�����ȫ�ֱ�����ʹ�ý�������Ҫ�ָ�ԭ״�����Ƿǳ���Ҫ��һ�� 
void dfs(int l)
{
	if(l==maxn){
		print();
		cnt++;
	}else{
		for(int r=0;r<maxn;r++)
			for(int c=0;c<maxn;c++){
				if(map[r][c]==0){
					map[r][c]=l+1;
					hostile(r,c);
					dfs(l+1);
					undo(r,c);
					map[r][c]=0;
				}
			}
	}
}
/*
	����֪ʶ��
		���Խ��ߺ͸��Խ���
	y-x(��x-y)��ʶ���Խ��ߵı�ţ�
		0   1   2   3   4   5   6   7
		-1  0   1   2   3   4   5   6
		-2 -1   0   1   2   3   4   5
		-3 -2  -1   0   1   2   3   4
		-4 -3  -2  -1   0   1   2   3 
		-5 -4  -3  -2  -1   0   1   2
		-6 -5  -4  -3  -2  -1   0   1 
		-7 -6  -5  -4  -3  -2  -1   0
	x+y��ʶ���Խ��ߵı�ţ�
		0   1   2   3   4   5   6   7
		1   2   3   4   5   6   7   8
		2   3   4   5   6   7   8   9
		3   4   5   6   7   8   9   10
		4   5   6   7   8   9   10  11 
		5   6   7   8   9   10  11  12
		6   7   8   9   10  11  12  13 
		7   8   9   10  11  12  13  14 
		
		  
*/

//���⣬ע�⵽ÿ���ʺ��ڲ�ͬ���к��У����ÿ�лʺ��λ�����һ������
// ��X����¼������У������еĽ�����ݹ����� 
int X[maxn]; //X��¼���� 
int vis[3][maxn*maxn];//��¼�õ����У����Խ��ߺ͸��Խ������Ƿ���� 
void printn()
{
	for(int r=0;r<maxn;r++){
		for(int c=0;c<maxn;c++)
			if(c==X[r])cout<<1<<" ";
			else cout<<0<<" ";
		cout<<endl;
	}
	cout<<endl; 
}
//�жϸõ��Ƿ���ߵ�����ͨ��ģ������������õ� 
void dfsn(int cur)
{
	if(cur==maxn){
		printn();
		cnt++;
		return;
	}else{
		for(int i=0;i<maxn;i++){
			X[cur]=i; 
			if(map[cur][i]==0){
				map[cur][i]=1;
				hostile(cur,i);
				dfsn(cur+1);
				undo(cur,i);
				map[cur][i]=0;
			}
		}
	}
}
//�жϸõ��Ƿ���ߵ�������ʵ����ģ��������� 
void dfsn1(int cur)
{
	if(cur==maxn){
		printn();
		cnt++;
		return;
	}else{
		for(int i=0;i<maxn;i++){
			X[cur]=i; 
			int ok=1;
			for(int j=0;j<cur;j++){
				if(X[cur]==X[j]||cur-j==X[j]-X[cur]||cur-j==X[cur]-X[j]){
					ok=0;
					break;
				}
			}
			if(ok){
				dfsn1(cur+1);
			}
		}
	}
} 
//������ά��������¼�����ٵõ��Ƿ���ߵ����� 
void dfsn2(int cur)
{
	if(cur==maxn){
		printn();
		cnt++;
		return;
	}else{
		for(int i=0;i<maxn;i++){
			X[cur]=i; 
			if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+maxn]){
				vis[0][i]=vis[1][cur+i]=vis[2][cur-i+maxn]=1;
				dfsn2(cur+1);
				vis[0][i]=vis[1][cur+i]=vis[2][cur-i+maxn]=0;
			}
		}
	}
} 
int main()
{
	cnt=0;
	init();
//	dfsn(0);
//	dfsn1(0);
	dfsn2(0);	
	cout<<"�������cnt: "<<cnt<<endl;
	return 0;
}
