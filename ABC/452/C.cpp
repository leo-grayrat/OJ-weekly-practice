#include <bits/stdc++.h>
using namespace std;
#define int long long

using v=vector<int>;
using vs=vector<string>;
signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n; cin>>n;
	v a(n),b(n);
	for(int i=0; i<n; ++i){
		cin>>a[i]>>b[i];
	}
	int m; cin>>m;
	vs s(m); v mask(m,0);
	for(auto& ele:s) {
		cin>>ele;
		for(int i=0; i<n; ++i){
			if(ele[a[i]-1]b[i])
		}
	}
	
	for(auto& ele:s){
		if(ele.size()!=n){
			cout<<"No"<<'\n';
		}
		
	}
}
