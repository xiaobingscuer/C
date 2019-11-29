// UVa11212 Editing a Book
// Rujia Liu
// This implementation is not very fast, but easy to understand
//这不是最快的实现，但是很好理解 
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 9; //最大深度 
int n, a[maxn]; //a是状态序列 

//判断是否有序 
bool is_sorted() {
  for(int i = 0; i < n-1; i++)
    if(a[i] >= a[i+1]) return false;
  return true;
}

// the number of integers with incorrect successor
//求序列中不正确后继元的数量，作为启发函数，用来度量到目标解的距离 
int h() {
  int cnt = 0;
  for(int i = 0; i < n-1; i++)
    if(a[i]+1 != a[i+1]) cnt++;
  if(a[n-1] != n) cnt++;
  return cnt;
}

//迭代加深A*搜索，IDA*搜素 
//d是当前节点的深度，maxd最大深度 
bool dfs(int d, int maxd) {
  if(d*3 + h() > maxd*3) return false; //如果不满足启发距离，则限制在该节点处扩展，直接返回上一个状态，在上一个状态扩展其他的选择 
   									   //启发距离可以作为递归基，限制深度， 
  if(is_sorted()) return true; //判断结点是否是目标解 

  int b[maxn], olda[maxn];
  memcpy(olda, a, sizeof(a));//拷贝序列 
  //横向选择剪切的区间 
  for(int i = 0; i < n; i++)
   for(int j = i; j < n; j++) {
     // cut
     //剪切  
     int cnt = 0;
     for(int k = 0; k < n; k++)
       if(k < i || k > j) b[cnt++] = a[k];//将剪切后剩余的序列保存起来 

     // insert before position k
     //每次剪切n-cnt长度的序列后，又有cnt+1个新的粘贴位置
	 //每次剪切后再粘贴就可以产生很多新的后序状态 
     for(int k = 0; k <= cnt; k++) {
       int cnt2 = 0;
       for(int p = 0; p < k; p++) a[cnt2++] = b[p];
       for(int p = i; p <= j; p++) a[cnt2++] = olda[p];
       for(int p = k; p < cnt; p++) a[cnt2++] = b[p];
       if(dfs(d+1, maxd)) return true;  //纵向的下一步 ,如果该分支找到解就直接退出 
     }
     memcpy(a, olda, sizeof(a)); //恢复到开始状态，进行下次剪切 
   }
  return false;
}

//迭代加深搜索的主函数 
//返回解->经过的步数->深度 
int solve() {
  if(is_sorted()) return 0;
  int max_ans = 5; // after experiments, we found ans <= 5 for n <= 9
  for(int maxd = 1; maxd < max_ans; maxd++) //从1开始的不同的深度 
    if(dfs(0, maxd)) return maxd;
  return max_ans;
}

int main() {
  int kase = 0;
  while(scanf("%d", &n) == 1 && n) {
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Case %d: %d\n", ++kase, solve());
  }
  return 0;
}
