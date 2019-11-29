// UVa1354 Mobile Computing
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

//核心思想：二进制法穷举子集，此子集作为左子树，那么右子树就是此子集的补集，然后自底向上后序递归穷举 
struct Tree {
  double L, R; // distance from the root to the leftmost/rightmost point
  Tree():L(0),R(0) {}
};

const int maxn = 6;

int n, vis[1<<maxn];
double r, w[maxn], sum[1<<maxn];
vector<Tree> tree[1<<maxn];
//假设吊坠有4个 
void dfs(int subset) { //第一层subset=root=15(1111) 
  if(vis[subset]) return; 
  vis[subset] = true; //子集访问标志置位 ，在递归完后并没有取消访问标志，为避免重复穷举左子集，反正作左子集总共2^n-2种情况，已经求解过的子集不用再求解了 

  bool have_children = false; //没有子集时就代表叶节点（挂坠） 
  for(int left = (subset-1)&subset; left; left = (left-1)&subset) { //对子集再分子集，subset=15时，1=<left<=14,保证一定有个吊坠 
    have_children = true;
	
    int right = subset^left; //对左子集(左子树）求补得到右子集(右子树) ，left+right=15 
    double d1 = sum[right] / sum[subset]; //左子树的棍长=右子树的吊坠总重量/所有吊坠的总重量 
    double d2 = sum[left] / sum[subset]; //右子树的棍长=左子树的吊坠总重量/所有吊坠的总重量 

    dfs(left); dfs(right); //对左右子树进行递归 
    
    for(int i = 0; i < tree[left].size(); i++)
      for(int j = 0; j < tree[right].size(); j++) {
        Tree t;
        t.L = max(tree[left][i].L + d1, tree[right][j].L - d2); //左子树和右子树的棍可以重叠，也就是说子树的棍可能比该结点的棍更长 
        t.R = max(tree[right][j].R + d2, tree[left][i].R - d1);
        if(t.L + t.R < r) tree[subset].push_back(t); //把满足条件的子树加入到树中 
      }
  }

  if(!have_children) tree[subset].push_back(Tree()); //没有子集时就是叶节点，此时就是挂坠，添加空结点 
}

int main() {
  int T; //数据组数 T
  scanf("%d", &T);
  while(T--) { //每组数据的求解 
    scanf("%lf%d", &r, &n); //房间宽度r和吊坠数量n
    for(int i = 0; i < n; i++) scanf("%lf", &w[i]);//每个吊坠的质量 
    for(int i = 0; i < (1<<n); i++) { //循环2^n次幂次 ，穷举子集 
      sum[i] = 0; //归零 并重新记录子集 的吊坠重量 
      tree[i].clear(); //清空 
      for(int j = 0; j < n; j++) 
        if(i & (1<<j)) sum[i] += w[j]; //判断子集包含哪些吊坠并累加此子集中的吊坠重量 
    }

    int root = (1<<n)-1; //root==2^n-1,4个挂坠，二进制穷举子集：0000~1111，即0-15这16种可能 
    memset(vis, 0, sizeof(vis));
    dfs(root); //求解 

    double ans = -1;
    for(int i = 0; i < tree[root].size(); i++)
      ans = max(ans, tree[root][i].L + tree[root][i].R); //在所有可能的解里找最优解 
    printf("%.10lf\n", ans);
  }
  return 0;
}



