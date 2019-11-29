
/*
	Name: 子集生成 
	Copyright: @lxber 
	Author: lxb 
	Date: 26/11/17 10:52
	Description: 穷举集合 S 的所有子集 
	参考：算法竞赛入门经典（第2版）第七章 
*/
/*
	问题陈述：有 n 个元素的集合 S={0,1,2,3...n-1} ,这 n 个元素互不相同，且已按从 
			  小到大的顺序排序，问题是：如何穷举集合 S 的所有可能的子集？
	子集个数：M=C(n,0)+C(n,1)+...+C(n,n)=2^n		   
*/
/*
	增量构造法：用数组 A 来保存子集，将 S 中的元素依次填入 A[cur],填入的条件是
				A[cur+1]>A[cur]。假设 S={0,1,2},增量构造法的解答树为：
							(*,*,*)
							/   |  \
					(0,*,*) (1,*,*) (2,*,*)
					/  \       |       
			(0,1,*)  (0,2,*)  (1,2,*)
			   |
			(0,1,2)
			这颗解答树总共有 2^3=8 个节点，推而广之，对于 n 个元素的集合 S,
			增量构造法有 2^n 个节点。
			
	位向量法：用数组 B 标记元素是否被选中，B[i]=1,表示元素 i 被选中；B[i]=0,表示
			  元素 i 未被选中。假设 S={0,1,2},位向量法的解答树为：
			  				        	(*,*,*)
							            /      \
						         (0,*,*)	    (1,*,*)
						        /	 \           /     \
						(0,0,*)   (0,1,*)    (1,0,*)    (1,1,*)
					   /  \       /    \      /    \      /    \
			  (0,0,0)(0,0,1)(0,1,0)(0,1,1)(1,0,0)(1,0,1)(1,1,0)(1,1,1)
			这颗解答树总共有 2^4-1=15 个节点，推而广之，对于 n 个元素的集合 S,
			增量构造法有 2^(n+1)-1 个节点。
	
	二进制法：对位向量法的改进，用位来替代 B[i],具体如下图：
				bits: 0   1  0  0  0  1  1 0 0 0 1 1 0 1 1 1
			元素标号：15 14 13 12 11 10  9 8 7 6 5 4 3 2 1 0
			 							| 
			得到子集：           14 10 9 5 4 2 1 0
			bits可以用整数 A来表示，空集就是 A=0，全集就是 A 中的元素全为 1, 
			假设全集用ALL_BITS来表示，那么ALL_BITS=(2^n-1)=(1<<n)-1,
			那么子集 A,B的交集就是 A&B,并集 A|B,对称集 A^B. 
			子集 A的补集就是 ALL_BITS^A. 
		附：逻辑元素、位运算与集合运算  
*/

#include <iostream>
using namespace std;
//增量构造法
void subset_inc(int n,int *A,int cur)
{
	for(int i=0;i<cur;i++)cout<<A[i]<<" ";
	cout<<endl;
	int s=cur?A[cur-1]+1:0;
	for(int i=s;i<n;i++){
		A[cur]=i;
		subset_inc(n,A,cur+1);
	}
}
//位向量法
void subset_bmap(int n,int *B,int cur)
{
	if(cur==n){
		for(int i=0;i<n;i++)
			if(B[i])cout<<i<<" ";
		cout<<endl;
		return;
	}
	for(int i=1;i>=0;i--){
		B[cur]=i;
		subset_bmap(n,B,cur+1);
	}
}
//二进制法
void subset_binary(int n)
{
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++)
			if(i&(1<<j))cout<<j<<" ";
		cout<<endl;
	}	
} 
 

int main() 
{
	int A[3];
	int B[3];
	subset_inc(3,A,0);
//	subset_bmap(3,B,0);
//	subset_binary(3);
	return 0;
}

