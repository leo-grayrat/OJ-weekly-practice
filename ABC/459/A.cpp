#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;

void solve(){
	int n; cin>>n;
	string ori="HelloWorld";
	ori.erase(ori.begin()+n-1);
	cout<<ori;
}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
//	int n; cin>>n;
//	for(int i=0; i<n; ++i){
//		solve();
//	}
	solve();
}
