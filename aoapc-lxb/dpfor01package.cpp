
#include<cstdio> 
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* dp 求解01背包问题过程中遇到的问题
 1、价值空间复杂度--从二维O(M*V)到一维O(V)
 2、恰好装满背包与只需得到最大价值不一定要装满--初始化时 
 3、记录问题的解或路径-- 二维价值空间与一维路径空间逆向求解 
*/ 
// 定义物品的数据结构 
struct goods{
    int w,v; //重量w和价值v 
};
/* 二维数组，空间开销太大O(M*V)
  不要求恰好装满-- 价值空间 v[][] 全部初始化为 0
  如果要求恰好装满-- 价值空间 v[][0]初始化为 0，其余为 负无穷
  从 v[M][V]开始向v[0][0]走，每次都要判断下 
*/
int dpforpackage1(const vector<goods>& vg,int V,int M){
    // 包的大小是V，有M个物品，v[][]为价值表 
    int v[M+1][V+1];
    memset(v,0,sizeof(v));
    for(int i=1;i<=M;i++){
    	for(int j=1;j<=V;j++){
    		int wi=j-vg[i-1].w;
            int vi=vg[i-1].v;
            if(wi>=0){
				v[i][j]=max(v[i-1][wi]+vi,v[i-1][j]);
			}else{
                v[i][j]=v[i-1][j]; 
            }
		}
	}
	// 逆向从价值空间中求得解或路径 
	vector<int> vr;
	for(int i=M,j=V;i>0&&j>0;i--) {
		if(v[i][j]==v[i-1][j-vg[i-1].w]+vg[i-1].v){
			vr.push_back(i);
			j-=vg[i-1].w;
		}
	}
	cout<<"第几个物品装入了背包："<<endl; 
	for(int i=0;i<vr.size();i++)cout<<vr[i]<<" ";
	cout<<endl;
	// 返回最大价值 
    return v[M][V];
}

/* 优化空间复杂度为O(V),即用一维数组value[V+1] 
  价值空间value[]从后向前推  
  恰好装满背包-- value[0]=0,其他初始化为负无穷比如 -100000 ？ 
  只希望价值最大并不一定是要装满--value[]全部初始为0 
  如何去记录解，定义二维路径空间path[][]
*/ 
int dpforpackage2(const vector<goods>& vg,int V,int M){
    // 包的大小是V，有M个物品
    // 路径空间path[M][V+1];
    int path[M][V+1];
    memset(path,0,sizeof(path));
    int value[V+1];value[0] =0;
    for(int i=1;i<=V;i++)value[i]=0; //初始化 
    for(int i=0;i<M;i++){
    	for(int j=V;j>=1;j--){ //从后向前推 
    		int wi=j-vg[i].w;
    		int vi=vg[i].v;
    		if(wi>=0){
				value[j]=max(value[wi]+vi,value[j]);
				// 记录解
				if(value[j]==value[wi]+vi)
					path[i][j]=1;
			}
			//if(i==m-1&&j==V)break;// 得到value[V]就停止 
		}
	}
	// 逆向从路径空间中求得解或路径 
	vector<int> vr;
	for(int i=M-1,j=V;i>=0&&j>0;i--) {
		if(path[i][j]==1){
			vr.push_back(i+1);
			j-=vg[i].w;
		}
	}
	cout<<"第几个物品装入了背包："<<endl; 
	for(int i=0;i<vr.size();i++)cout<<vr[i]<<" ";
	cout<<endl;
	// 返回价值 
    return value[V];
}
 
// 那么从前向后推呢？
 
int main(){
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int V,M;
    int w,v;
    vector<goods> vg;
    while(cin>>V>>M){ // 读入数据 
    	vg.clear(); // 清空已有的物品袋 重新装入物品 
        for(int i=0;i<M;i++){ 
            cin>>w>>v;
        	goods g;
            g.w=w;g.v=v;
            vg.push_back(g);
        }
        cout<<dpforpackage1(vg,V,M)<<endl; // 输出结果1 
        cout<<dpforpackage2(vg,V,M)<<endl; // 输出结果2
    }
    return 0;
}
