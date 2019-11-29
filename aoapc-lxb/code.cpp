


#include <iostream> 
#include <algorithm>
using namespace std;

int main(){
	double x11=0.2,x12=0.8,x21=0.6,x22=0.4;
	double t11=1,t12=0,t21=0,t22=1;
	double p11=x11,p12=x12,p21=x21,p22=x22;
	for(int i=0;i<200;i++){
		p11=t11*x11+t12*x21;
		p12=t11*x12+t12*x22;
		p21=t21*x11+t22*x21;
		p22=t21*x12+t22*x22;
		
		t11=p11;
		t12=p12;
		t21=p21;
		t22=p22;
		
	}

	cout<<"p11 "<<p11<<"  p12 "<<p12<<endl;
	cout<<"p21 "<<p21<<"  p22 "<<p22<<endl;
	 
	return 0;
}
