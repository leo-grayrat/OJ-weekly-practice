#include <bits/stdc++.h>
using namespace std;
//#define _GLIBCXX_DEBUG

int main(){
	string a,b;
	getline(cin,a);
//cin>>a;
	b=a;
	transform(b.begin(),b.end(),b.begin(),::tolower);
	
	size_t res=b.find("fuck");
	while(res!=string::npos){
		for(int i=0; i<4; ++i){
			b.at(i+res)='*';
			a.at(i+res)='*';
		}
		res=b.find("fuck");
	}
	
	cout<<a;
}
