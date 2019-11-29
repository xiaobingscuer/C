
//总结：
//I/O:
//文件打开方式：ios::in读/ios::out打开/ios::trunc不存在创建，存在则清空； 
//流家族：
//							 ios 
//                 	       /     \
//		           istream        ostream
//               /     |   \     /     |    \
//    istrstream ifstream iostream ofstream ostrstream
//                          /  \              
//                 strstream   fstream

//不可赋值和复制： 

#include <iostream>
#include <fstream> 
using namespace std;

int main(){
	fstream fs("input.txt",ios::in|ios::out|ios::trunc);
	if(!fs)cout<<"error"<<endl;
	fs.put('L');
	fs.seekg(0,ios::beg);
	fs<<"lixiaobiing,2018/2/26.";

	fs.close();
	
}
