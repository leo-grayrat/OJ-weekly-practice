#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;


void solve(){
	v all(3); int d;
	for(auto& ele: all) cin>>ele;
	cin>>d;
	
	sort(all.begin(),all.end());
	int res=max(d-(all[2]-all[1]),0ll)+max(d-(all[1]-all[0]),0ll);
	
	cout<<res<<'\n';
}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
//	int n; cin>>n;
//	
//	for(int i=0; i<n; ++i){
//		solve();
//	}
	
	solve();
}
