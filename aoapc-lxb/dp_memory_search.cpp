
/*
	Name: ���ڶ�̬�滮�ͼ��仯���� 
	Copyright: 
	Author: lxb 
	Date: 25/11/17 10:25
	Description: 
	  �ο���1
	        2��https://www.cnblogs.com/fu11211129/p/4276213.html 
*/

#include <iostream>
#include <cstring>
using namespace std;

/*
	�Შ�������еı�׼�ݹ顢��̬�滮�ͼ��仯�������ַ������ 
*/
int fd[1005];
// ��׼�ݹ� 
int fstd(int n)
{
	return (n<=1)?n:fstd(n-1)+fstd(n-2);
}
// ��̬�滮
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
// ���仯����
int fmem(int n)
{
	if(n==0)return fd[0]=0;
	if(n==1)return fd[1]=1;
	if(fd[n]>=0)return fd[n];
	else return fd[n]=fmem(n-1)+fmem(n-2);
} 
/*
	���Შ������������ļ��仯�����Ͷ�̬�滮��������
	1.��̬�滮�Ǵ��µ��ϣ�����������Ľ��Ƶ�ԭ����Ľ⣻
	  ���仯�����Ǵ��ϵ��£�����ԭ�����������������Ľ�,�������ѽ����ֱ��ʹ�ã�������Ⲣ��¼ 
	2.��̬�滮ʹ�õ�������ʽ�����仯�������ǵݹ���������ʽ
	3.��̬�滮��Ҫ�����������ⶼ��Ҫ�����
	  ���һ���������Ѿ���������仯������ֱ�Ӳ��ʹ�ö����ؼ��㣬�Ӷ�ʵ�ּ�֦ 
	  ������������ģԽ��Խ������仯������Խ��Խ�� 
	4.���仯�����붯̬�滮����Ҫ���ŵ��ƹ�ϵ 
*/
/*
	��ѩ����ļ��仯������� 
	���������
				1	2	3	4
				12	13	14	5
				11	16	15	6
				10	9	8	7
			����ľ������ѩ���ĺ��θ߶ȣ��ܴ�һ��λ�û�������λ�õ�������������λ�õ�
			�߶Ȳ����0�����軬ѩ���붨��Ϊ����λ�õ�������������ֻ�ܴ���ԭλ��ʱ��ѩ����Ϊ1 
			���������ĸ�λ�ÿ��Ի�����Զ����Զ�ľ����Ƕ��٣� 
	˼·������λ�ã�i,j)�ܻ������ڵ��ĸ�λ�ã�
		  ��ô�Ӹ�λ�û�ѩ�ľ�����ڴӸ�λ�����ڵ��ĸ�λ�û�ѩ�ľ���+1 
	���ŵĵ��ƹ�ϵ��dp[i][j]=max(dp[i-1][j],dp[i][j+1],dp[i+1][j],dp[i][j-1])+1 ��dpΪ������						
*/
//���仯������⻬ѩ���� 
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
	�а�������ļ��仯�����Ͷ�̬�滮��� 
	���������
				���ӳ��� i��1  2  3  4   5   6   7   8   9  10
				��Ӧ�۸� p��1  5  8  9  10  17  17  20  24  30 
			������ ������Զ԰��ӽ����и��ô��һ������Ϊ i �İ��ӣ�������������ļ۸� 
	���ŵ��ƹ�ϵ��dp[i]=max(p(j)+dp[i-j],j=1,2...10) ��dp[]Ϊ���ż۸�� 
*/
// ���仯��������а������� 
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
	01��������ļ��仯����
	������������ M ����ͬ����Ʒ����һ������Ϊ N �İ����� i ����Ʒ������Ϊ w[i],��ֵΪ v[i]��
			  ������  ����Щ��Ʒװ�뱳������Ի������ֵ�� 
	���ŵ��ƹ�ϵ�� ��dp[i][j]��ʾ��Ʒi�����СΪj�İ����õļ�ֵ����ô���ŵ��ƹ�ϵΪ
					dp[i][j]=max(dp[i-1][j-w[i]]+v[i],dp[i-1][j])
				�Ӷ�ά�ռ䵽һά�ռ�,�Ӻ���ǰ���� 
					dp[j]=max(dp[j-w[i]]+v[i],dp[j])
	01��������ο���
		1. http://blog.csdn.net/mu399/article/details/7722810 
*/
//���仯�������01�������� 
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
	�ܽ᣺ 
	���仯����ģ�壺
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

