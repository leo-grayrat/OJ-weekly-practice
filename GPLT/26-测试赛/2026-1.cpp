#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	for(int i=0; i<15; ++i){
		string name; cin>>name;
		int ac; cin>>ac;
		
		cout<<name;
		if(ac==0) cout<<" L3";
		else if(ac==n) cout<<" L1";
		else cout<<" L2";
		cout<<'\n';
	}
}
