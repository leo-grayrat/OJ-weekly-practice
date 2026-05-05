#include <bits/stdc++.h>
using namespace std;

int valid(char a){
	if(a>='0'&&a<='9') return 1;
	if(a>='a'&&a<='z') return 1;
	if(a>='A'&&a<='Z') return 1;
	else return 0;
}

int main(){
	int n=0;
	string inp;
	getline(cin,inp);
	for(char scan:inp){
		n+=valid(scan);
	}
	cout<<n;
}

