#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<string>;


void solve(){
	int n; cin>>n;
	int res=0;
	for(int i=0; i<n; ++i){
		int t; cin>>t;
		res+=(t-1);
	}
	if(res%2==0) cout<<"maomao90\n";
	else cout<<"errorgorn\n";
}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin>>n;
	
	for(int i=0; i<n; ++i){
		solve();
	}
}
