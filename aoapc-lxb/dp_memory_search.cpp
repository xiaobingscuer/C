
/*
	Name: 关于动态规划和记忆化搜索 
	Copyright: 
	Author: lxb 
	Date: 25/11/17 10:25
	Description: 
	  参考：1
	        2：https://www.cnblogs.com/fu11211129/p/4276213.html 
*/

#include <iostream>
#include <cstring>
using namespace std;

/*
	裴波那契数列的标准递归、动态规划和记忆化搜索三种方法求解 
*/
int fd[1005];
// 标准递归 
int fstd(int n)
{
	return (n<=1)?n:fstd(n-1)+fstd(n-2);
}
// 动态规划
int fdp(int n)
{
	int g=0,h=1;
	if(n==0)return g;
	if(n==1)return h;
	for(int i=1;i<n;i++){
		h+=g;
		g=h-g;
	}
	return h;
}
// 记忆化搜索
int fmem(int n)
{
	if(n==0)return fd[0]=0;
	if(n==1)return fd[1]=1;
	if(fd[n]>=0)return fd[n];
	else return fd[n]=fmem(n-1)+fmem(n-2);
} 
/*
	求裴波那契数列问题的记忆化搜索和动态规划求解的区别：
	1.动态规划是从下到上，即从子问题的解推到原问题的解；
	  记忆化搜索是从上到下，即从原问题出发查找子问题的解,子问题已解决则直接使用，否则求解并记录 
	2.动态规划使用迭代的形式；记忆化搜索仍是递归搜索的形式
	3.动态规划需要把所有子问题都需要求出；
	  如果一个子问题已经求过，记忆化搜索会直接查表使用而不必计算，从而实现剪枝 
	  如果求解的问题规模越来越大，则记忆化搜索会越算越快 
	4.记忆化搜索与动态规划都需要最优递推关系 
*/
/*
	滑雪问题的记忆化搜索求解 
	问题陈述：
				1	2	3	4
				12	13	14	5
				11	16	15	6
				10	9	8	7
			上面的矩阵代表雪场的海拔高度，能从一个位置滑到相邻位置的条件是这两个位置的
			高度差大于0，假设滑雪距离定义为经过位置的数量，因此如果只能处于原位置时滑雪距离为1 
			问题是在哪个位置可以滑得最远，最远的距离是多少？ 
	思路：假设位置（i,j)能滑到相邻的四个位置，
		  那么从该位置滑雪的距离等于从该位置相邻的四个位置滑雪的距离+1 
	最优的递推关系：dp[i][j]=max(dp[i-1][j],dp[i][j+1],dp[i+1][j],dp[i][j-1])+1 ，dp为最长距离表						
*/
//记忆化搜索求解滑雪问题 
const int maxn=10; 
int h[maxn][maxn],dp[maxn][maxn];
int R,C;
int dx[]={-1,0,1,0};//up right down left
int dy[]={0,1,0,-1};
bool inMap(int i,int j)
{
	if(i<0||i>=R)return false;
	if(j<0||j>=C)return false;
	return true;
}
int dpmem(int i,int j)
{
	int du=0,dr=0,dd=0,dl=0; 
	int ni,nj;
	if(!inMap(i,j))return -1;
	if(dp[i][j]>0)return dp[i][j];
	else{
		// up
		ni=i+dx[0];
		nj=j+dy[0];
		if(inMap(ni,nj))if(h[i][j]>h[ni][nj])du=dpmem(ni,nj);
		// right
		ni=i+dx[1];
		nj=j+dy[1];
		if(inMap(ni,nj))if(h[i][j]>h[ni][nj])dr=dpmem(ni,nj);
		// down
		ni=i+dx[2];
		nj=j+dy[2];
		if(inMap(ni,nj))if(h[i][j]>h[ni][nj])dd=dpmem(ni,nj);
		// left
		ni=i+dx[3];
		nj=j+dy[3];
		if(inMap(ni,nj))if(h[i][j]>h[ni][nj])dl=dpmem(ni,nj);
	}
	dp[i][j]=max(max(du,dr),max(dd,dl))+1;  //record the ans of sub problem
	return dp[i][j];
}
/*
	切棒子问题的记忆化搜索和动态规划求解 
	问题陈述：
				棒子长度 i：1  2  3  4   5   6   7   8   9  10
				对应价格 p：1  5  8  9  10  17  17  20  24  30 
			问题是 假设可以对棒子进行切割，那么卖一个长度为 i 的棒子，可以最多卖出的价格？ 
	最优递推关系：dp[i]=max(p(j)+dp[i-j],j=1,2...10) ，dp[]为最优价格表 
*/
// 记忆化搜索求解切棒子问题 
const int maxl=10;
int p[maxl],dpl[maxl+5];
int dpmeml(int l)
{
	if(l<=0)return dpl[0]=0;
	if(dpl[l]>0)return dpl[l];
	else{
		for(int j=1;j<=maxl;j++)
			if(l-j>=0)
				dpl[l]=max(dpl[l],p[j-1]+dpmeml(l-j));	
	}
	return dpl[l];
}
/*
	01背包问题的记忆化搜索
	问题描述：有 M 件不同的物品，有一个承重为 N 的包。第 i 件物品的重量为 w[i],价值为 v[i]，
			  问提是  将哪些物品装入背包里可以获得最大价值？ 
	最优递推关系： 以dp[i][j]表示物品i放入大小为j的包后获得的价值，那么最优地推关系为
					dp[i][j]=max(dp[i-1][j-w[i]]+v[i],dp[i-1][j])
				从二维空间到一维空间,从后向前更新 
					dp[j]=max(dp[j-w[i]]+v[i],dp[j])
	01背包问题参考：
		1. http://blog.csdn.net/mu399/article/details/7722810 
*/
//记忆化搜索求解01背包问题 
const int M=5;
const int N=10;
const int w[]={0,4,5,6,2,2};
const int v[]={0,6,4,5,3,6};
int dpv[M+1][N+1];
int dpmemv(int i,int j)
{
	if(i==0||j<=0)return 0;
	if(dpv[i][j]>=0)return dpv[i][j];
	else{
		if(j<w[i]) dpv[i][j]=dpmemv(i-1,j);
		else dpv[i][j]=max(dpmemv(i-1,j-w[i])+v[i],dpmemv(i-1,j));
	}
	return dpv[i][j];
}

/*
	总结： 
	记忆化搜索模板：
	a table dp[] for solutions of problems
	solution-type dpmem(problem a)
	{
		if(a is fundamental problem)return dp[base];
		if(a has been solved)return dp[a];
		else{
			// record the optimal solution of problem a that is contributed by 
			// optimal solutions of sub-problems(a1,a2,..,an)
			dp[a]=optimal(dpmem(a1),dpmem(a2),...,dpmem(an));
		}
		return dp[a];
	} 
*/

int main(){
	for(int i=0;i<M+1;i++)
	for(int j=0;j<N+1;j++)
	dpv[i][j]=-1;
	
	int ans=0;
	for(int i=0;i<M+1;i++)
	for(int j=0;j<N+1;j++)
	ans=max(ans,dpmemv(i,j));
	cout<<ans<<endl;
	
	for(int i=0;i<M+1;i++)
	{
		for(int j=0;j<N+1;j++)
		cout<<dpv[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

