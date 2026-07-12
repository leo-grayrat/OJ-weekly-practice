#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;
using m=map<int,int>;

bool cmp(const pair<int, int>& l,  const pair<int, int>& r) {
	return l.second < r.second;
}


void solve(){
	int k; cin>>k;
	m all;
	
	int ii=k;
	while(ii>0){
		--ii;
		int t; cin>>t;
		++all[t];
	}
	
	auto maxi=max_element(all.begin(),all.end(),cmp);
	int ga=maxi->second;
	
	int gb=all.size();
	
	int res=max(min(ga,gb-1),min(ga-1,gb));
	cout<<res<<'\n';
}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin>>n;
	
	for(int i=0; i<n; ++i){
		solve();
	}
	
//	solve();
}
