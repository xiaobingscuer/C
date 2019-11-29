// UVa1343 The Rotation Game
// Rujia Liu
// This solutions uses IDA* instead of BFS described in the book, because it's shorter 8-)
// It's shorter because no need for lookup tables and "automatically" lexicographically smallest solution.
#include<cstdio>
#include<algorithm>
using namespace std;

/*
      00    01
      02    03
04 05 06 07 08 09 10
      11    12
13 14 15 16 17 18 19
      20    21
      22    23
*/

// lines E~H are computed with the help of rev[]
int line[8][7]={
  { 0, 2, 6,11,15,20,22}, // A
  { 1, 3, 8,12,17,21,23}, // B
  {10, 9, 8, 7, 6, 5, 4}, // C
  {19,18,17,16,15,14,13}, // D
};

const int rev[8] = {5, 4, 7, 6, 1, 0, 3, 2}; // reverse lines of each line

// center squares
const int center[8] = {6, 7, 8, 11, 12, 15, 16, 17};

int a[24];
char ans[1000];

bool is_final() {
  for(int i = 0; i < 8; i++)
    if (a[center[i]] != a[center[0]]) return false;
  return true;
}

int diff(int target) {
  int ans = 0;
  for(int i = 0; i < 8; i++)
    if(a[center[i]] != target) ans++;
  return ans;
}
//启发距离表示为：到三个目标的"异或距离(^,汉明距离)"的最小值 
inline int h() {
  return min(min(diff(1), diff(2)), diff(3));
}

inline void move(int i) {
  int tmp = a[line[i][0]];
  for(int j = 0; j < 6; j++) a[line[i][j]] = a[line[i][j+1]];
  a[line[i][6]] = tmp;
}

bool dfs(int d, int maxd) {
  if(is_final()) { //判断深度为maxd时的状态是否为目标解状态 
    ans[d] = '\0';
    printf("%s\n", ans);
    return true;
  }  
  if(d + h() > maxd) return false; //离开始状态的距离+到目标的启发距离 > maxd -> 作为递归基,且此状态肯定不是目标解，直接返回该支路未找到解状态false 
  for(int i = 0; i < 8; i++) {
    ans[d] = 'A' + i; //记录当前深度上执行的操作 
    move(i); //执行操作 'A'+i,改变当前状态，进行状态转移 
    if(dfs(d+1, maxd)) return true; //对改变的状态进行递归操作，如果该支路找到解则直接退出 
    move(rev[i]); //撤销操作 'A'+i,将状态恢复到之前的状态,因为下一次也是在原有的状态上进行改变，不是在改变的基础上进行改变 
  }
  return false; //如果在该状态的所有选择支路里都没找到解，则返回未找到解状态 
}

int main() {
  //构造前4个序列的逆序列 
  for(int i = 4; i < 8; i++)
    for(int j = 0; j < 7; j++) line[i][j] = line[rev[i]][6-j];
	
  while(scanf("%d", &a[0]) == 1 && a[0]) {
    for(int i = 1; i < 24; i++) scanf("%d", &a[i]);
    for(int i = 0; i < 24; i++) if(!a[i]) return 0;
    if(is_final()) {
      printf("No moves needed\n");
    } else {
      for(int maxd = 1; ; maxd++)
        if(dfs(0, maxd)) break;
    }
    printf("%d\n", a[6]);
  }
  return 0;
}
