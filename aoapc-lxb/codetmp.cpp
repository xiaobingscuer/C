
//�ܽ᣺
//I/O:
//�ļ��򿪷�ʽ��ios::in��/ios::out��/ios::trunc�����ڴ�������������գ� 
//�����壺
//							 ios 
//                 	       /     \
//		           istream        ostream
//               /     |   \     /     |    \
//    istrstream ifstream iostream ofstream ostrstream
//                          /  \              
//                 strstream   fstream

//���ɸ�ֵ�͸��ƣ� 

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
