#include <bits/stdc++.h>
using namespace std;
//#define int long long

using v=vector<int>;

void full(int m){
	for(int i=0; i<m; ++i){
		cout<<"#";
	}cout<<"\n";
}

void nful(int m){
	cout<<"#";
	for(int i=0; i<m-2; ++i){
		cout<<".";
	}
	cout<<"#\n";
}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n,m; cin>>n>>m;
	
	full(m);
	for(int i=0; i<n-2; ++i){
		nful(m);
	}
	full(m);
}
