
#include <iostream>
using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	char str[smax];
	cin.getline(str,smax);//不保留换行 
	cin.get(str,smax);//保留换行 
	
	string s;
	getline(cin,s);
	
	return 0;
}

