
#include<cstdio> 
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* dp ���01�����������������������
 1����ֵ�ռ临�Ӷ�--�Ӷ�άO(M*V)��һάO(V)
 2��ǡ��װ��������ֻ��õ�����ֵ��һ��Ҫװ��--��ʼ��ʱ 
 3����¼����Ľ��·��-- ��ά��ֵ�ռ���һά·���ռ�������� 
*/ 
// ������Ʒ�����ݽṹ 
struct goods{
    int w,v; //����w�ͼ�ֵv 
};
/* ��ά���飬�ռ俪��̫��O(M*V)
  ��Ҫ��ǡ��װ��-- ��ֵ�ռ� v[][] ȫ����ʼ��Ϊ 0
  ���Ҫ��ǡ��װ��-- ��ֵ�ռ� v[][0]��ʼ��Ϊ 0������Ϊ ������
  �� v[M][V]��ʼ��v[0][0]�ߣ�ÿ�ζ�Ҫ�ж��� 
*/
int dpforpackage1(const vector<goods>& vg,int V,int M){
    // ���Ĵ�С��V����M����Ʒ��v[][]Ϊ��ֵ�� 
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
	// ����Ӽ�ֵ�ռ�����ý��·�� 
	vector<int> vr;
	for(int i=M,j=V;i>0&&j>0;i--) {
		if(v[i][j]==v[i-1][j-vg[i-1].w]+vg[i-1].v){
			vr.push_back(i);
			j-=vg[i-1].w;
		}
	}
	cout<<"�ڼ�����Ʒװ���˱�����"<<endl; 
	for(int i=0;i<vr.size();i++)cout<<vr[i]<<" ";
	cout<<endl;
	// ��������ֵ 
    return v[M][V];
}

/* �Ż��ռ临�Ӷ�ΪO(V),����һά����value[V+1] 
  ��ֵ�ռ�value[]�Ӻ���ǰ��  
  ǡ��װ������-- value[0]=0,������ʼ��Ϊ��������� -100000 �� 
  ֻϣ����ֵ��󲢲�һ����Ҫװ��--value[]ȫ����ʼΪ0 
  ���ȥ��¼�⣬�����ά·���ռ�path[][]
*/ 
int dpforpackage2(const vector<goods>& vg,int V,int M){
    // ���Ĵ�С��V����M����Ʒ
    // ·���ռ�path[M][V+1];
    int path[M][V+1];
    memset(path,0,sizeof(path));
    int value[V+1];value[0] =0;
    for(int i=1;i<=V;i++)value[i]=0; //��ʼ�� 
    for(int i=0;i<M;i++){
    	for(int j=V;j>=1;j--){ //�Ӻ���ǰ�� 
    		int wi=j-vg[i].w;
    		int vi=vg[i].v;
    		if(wi>=0){
				value[j]=max(value[wi]+vi,value[j]);
				// ��¼��
				if(value[j]==value[wi]+vi)
					path[i][j]=1;
			}
			//if(i==m-1&&j==V)break;// �õ�value[V]��ֹͣ 
		}
	}
	// �����·���ռ�����ý��·�� 
	vector<int> vr;
	for(int i=M-1,j=V;i>=0&&j>0;i--) {
		if(path[i][j]==1){
			vr.push_back(i+1);
			j-=vg[i].w;
		}
	}
	cout<<"�ڼ�����Ʒװ���˱�����"<<endl; 
	for(int i=0;i<vr.size();i++)cout<<vr[i]<<" ";
	cout<<endl;
	// ���ؼ�ֵ 
    return value[V];
}
 
// ��ô��ǰ������أ�
 
int main(){
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int V,M;
    int w,v;
    vector<goods> vg;
    while(cin>>V>>M){ // �������� 
    	vg.clear(); // ������е���Ʒ�� ����װ����Ʒ 
        for(int i=0;i<M;i++){ 
            cin>>w>>v;
        	goods g;
            g.w=w;g.v=v;
            vg.push_back(g);
        }
        cout<<dpforpackage1(vg,V,M)<<endl; // ������1 
        cout<<dpforpackage2(vg,V,M)<<endl; // ������2
    }
    return 0;
}
