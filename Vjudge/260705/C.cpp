#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;


void solve(){
	int n,k; cin>>n>>k;
	v all(k);
	for(auto& ele: all) cin>>ele;
	
	sort(all.begin(),all.end());
	
	int dis=0, cou=0;
	for(auto it=all.rbegin(); it!=all.rend(); ++it){
		dis+=(n-*it);
		
		if(dis>=n){ 
			break;
		}
		else{
			++cou;
		}
	}
	
	cout<<cou<<'\n';
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
