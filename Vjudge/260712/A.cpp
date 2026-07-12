#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;
using m=map<int,int>;


void solve(){
	int k; cin>>k; k*=2;
	v all(k);
	
	int ii=k;
	while(ii>0){
		--ii;
		cin>>all[ii];
	}
	
	sort(all.begin(),all.end());
	
	if(all[0]==all[k-1]){
		cout<<"-1"; return;
	}
	
	else{
		int ii=k;
		while(ii>1){
			--ii;
			cout<<all[ii]<<" ";
		}
		cout<<all[0];
	}
}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
//	
//	int n; cin>>n;
//	
//	for(int i=0; i<n; ++i){
//		solve();
//	}
	
	solve();
}
