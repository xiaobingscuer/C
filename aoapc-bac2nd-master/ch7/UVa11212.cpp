// UVa11212 Editing a Book
// Rujia Liu
// This implementation is not very fast, but easy to understand
//�ⲻ������ʵ�֣����Ǻܺ���� 
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 9; //������ 
int n, a[maxn]; //a��״̬���� 

//�ж��Ƿ����� 
bool is_sorted() {
  for(int i = 0; i < n-1; i++)
    if(a[i] >= a[i+1]) return false;
  return true;
}

// the number of integers with incorrect successor
//�������в���ȷ���Ԫ����������Ϊ��������������������Ŀ���ľ��� 
int h() {
  int cnt = 0;
  for(int i = 0; i < n-1; i++)
    if(a[i]+1 != a[i+1]) cnt++;
  if(a[n-1] != n) cnt++;
  return cnt;
}

//��������A*������IDA*���� 
//d�ǵ�ǰ�ڵ����ȣ�maxd������ 
bool dfs(int d, int maxd) {
  if(d*3 + h() > maxd*3) return false; //����������������룬�������ڸýڵ㴦��չ��ֱ�ӷ�����һ��״̬������һ��״̬��չ������ѡ�� 
   									   //�������������Ϊ�ݹ����������ȣ� 
  if(is_sorted()) return true; //�жϽ���Ƿ���Ŀ��� 

  int b[maxn], olda[maxn];
  memcpy(olda, a, sizeof(a));//�������� 
  //����ѡ����е����� 
  for(int i = 0; i < n; i++)
   for(int j = i; j < n; j++) {
     // cut
     //����  
     int cnt = 0;
     for(int k = 0; k < n; k++)
       if(k < i || k > j) b[cnt++] = a[k];//�����к�ʣ������б������� 

     // insert before position k
     //ÿ�μ���n-cnt���ȵ����к�����cnt+1���µ�ճ��λ��
	 //ÿ�μ��к���ճ���Ϳ��Բ����ܶ��µĺ���״̬ 
     for(int k = 0; k <= cnt; k++) {
       int cnt2 = 0;
       for(int p = 0; p < k; p++) a[cnt2++] = b[p];
       for(int p = i; p <= j; p++) a[cnt2++] = olda[p];
       for(int p = k; p < cnt; p++) a[cnt2++] = b[p];
       if(dfs(d+1, maxd)) return true;  //�������һ�� ,����÷�֧�ҵ����ֱ���˳� 
     }
     memcpy(a, olda, sizeof(a)); //�ָ�����ʼ״̬�������´μ��� 
   }
  return false;
}

//�������������������� 
//���ؽ�->�����Ĳ���->��� 
int solve() {
  if(is_sorted()) return 0;
  int max_ans = 5; // after experiments, we found ans <= 5 for n <= 9
  for(int maxd = 1; maxd < max_ans; maxd++) //��1��ʼ�Ĳ�ͬ����� 
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
