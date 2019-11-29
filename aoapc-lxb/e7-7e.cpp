// UVa1354 Mobile Computing
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

//����˼�룺�����Ʒ�����Ӽ������Ӽ���Ϊ����������ô���������Ǵ��Ӽ��Ĳ�����Ȼ���Ե����Ϻ���ݹ���� 
struct Tree {
  double L, R; // distance from the root to the leftmost/rightmost point
  Tree():L(0),R(0) {}
};

const int maxn = 6;

int n, vis[1<<maxn];
double r, w[maxn], sum[1<<maxn];
vector<Tree> tree[1<<maxn];
//�����׹��4�� 
void dfs(int subset) { //��һ��subset=root=15(1111) 
  if(vis[subset]) return; 
  vis[subset] = true; //�Ӽ����ʱ�־��λ ���ڵݹ����û��ȡ�����ʱ�־��Ϊ�����ظ�������Ӽ������������Ӽ��ܹ�2^n-2��������Ѿ��������Ӽ������������ 

  bool have_children = false; //û���Ӽ�ʱ�ʹ���Ҷ�ڵ㣨��׹�� 
  for(int left = (subset-1)&subset; left; left = (left-1)&subset) { //���Ӽ��ٷ��Ӽ���subset=15ʱ��1=<left<=14,��֤һ���и���׹ 
    have_children = true;
	
    int right = subset^left; //�����Ӽ�(���������󲹵õ����Ӽ�(������) ��left+right=15 
    double d1 = sum[right] / sum[subset]; //�������Ĺ���=�������ĵ�׹������/���е�׹�������� 
    double d2 = sum[left] / sum[subset]; //�������Ĺ���=�������ĵ�׹������/���е�׹�������� 

    dfs(left); dfs(right); //�������������еݹ� 
    
    for(int i = 0; i < tree[left].size(); i++)
      for(int j = 0; j < tree[right].size(); j++) {
        Tree t;
        t.L = max(tree[left][i].L + d1, tree[right][j].L - d2); //���������������Ĺ������ص���Ҳ����˵�����Ĺ����ܱȸý��Ĺ����� 
        t.R = max(tree[right][j].R + d2, tree[left][i].R - d1);
        if(t.L + t.R < r) tree[subset].push_back(t); //�������������������뵽���� 
      }
  }

  if(!have_children) tree[subset].push_back(Tree()); //û���Ӽ�ʱ����Ҷ�ڵ㣬��ʱ���ǹ�׹����ӿս�� 
}

int main() {
  int T; //�������� T
  scanf("%d", &T);
  while(T--) { //ÿ�����ݵ���� 
    scanf("%lf%d", &r, &n); //������r�͵�׹����n
    for(int i = 0; i < n; i++) scanf("%lf", &w[i]);//ÿ����׹������ 
    for(int i = 0; i < (1<<n); i++) { //ѭ��2^n���ݴ� ������Ӽ� 
      sum[i] = 0; //���� �����¼�¼�Ӽ� �ĵ�׹���� 
      tree[i].clear(); //��� 
      for(int j = 0; j < n; j++) 
        if(i & (1<<j)) sum[i] += w[j]; //�ж��Ӽ�������Щ��׹���ۼӴ��Ӽ��еĵ�׹���� 
    }

    int root = (1<<n)-1; //root==2^n-1,4����׹������������Ӽ���0000~1111����0-15��16�ֿ��� 
    memset(vis, 0, sizeof(vis));
    dfs(root); //��� 

    double ans = -1;
    for(int i = 0; i < tree[root].size(); i++)
      ans = max(ans, tree[root][i].L + tree[root][i].R); //�����п��ܵĽ��������Ž� 
    printf("%.10lf\n", ans);
  }
  return 0;
}



