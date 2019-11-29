
/*
	《算法竞赛入门经典 2》第七章例 7-4-1. 
	例题1：八皇后问题 
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
//初始化 
void init()
{
	for(int r=0;r<maxn;r++)
	for(int c=0;c<maxn;c++)
	map[r][c]=0;
}
//打印解 
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
//模拟攻击范围 
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
//撤销模拟过程 
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
//非正解，意外收获 
//自己想的，枚举的是maxn个不同的皇后依次放入而不相互攻击的方案，
//效果是选择可行的组合后再排列，即 C(maxn*maxn,maxn)*A(maxn,maxn)
//复杂度比单纯的组合和排列的时间复杂度都高 
//不过这里意外地获得了一种 分配内存和释放内存的递归方式
//这里使用了辅助的全局变量，使用结束了需要恢复原状，这是非常重要的一点 
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
	几何知识：
		主对角线和副对角线
	y-x(或x-y)标识主对角线的编号：
		0   1   2   3   4   5   6   7
		-1  0   1   2   3   4   5   6
		-2 -1   0   1   2   3   4   5
		-3 -2  -1   0   1   2   3   4
		-4 -3  -2  -1   0   1   2   3 
		-5 -4  -3  -2  -1   0   1   2
		-6 -5  -4  -3  -2  -1   0   1 
		-7 -6  -5  -4  -3  -2  -1   0
	x+y标识副对角线的编号：
		0   1   2   3   4   5   6   7
		1   2   3   4   5   6   7   8
		2   3   4   5   6   7   8   9
		3   4   5   6   7   8   9   10
		4   5   6   7   8   9   10  11 
		5   6   7   8   9   10  11  12
		6   7   8   9   10  11  12  13 
		7   8   9   10  11  12  13  14 
		
		  
*/

//正解，注意到每个皇后在不同的行和列，因此每行皇后的位置组成一个排列
// 用X来记录这个排列，按排列的解答树递归搜索 
int X[maxn]; //X记录排列 
int vis[3][maxn*maxn];//记录该点在列，主对角线和副对角线上是否可走 
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
//判断该点是否可走的条件通过模拟这个过程来得到 
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
//判断该点是否可走的条件其实不必模拟这个过程 
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
//借助二维数组来记录并快速得到是否可走的条件 
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
	cout<<"解的数量cnt: "<<cnt<<endl;
	return 0;
}
