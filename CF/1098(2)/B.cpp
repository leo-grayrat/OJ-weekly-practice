#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;

void solve(){
	int n,a,b,k; cin>>n>>a>>b>>k;
	int dis=min(abs(b-a),abs(n+b-a));
	cout << dis+k <<'\n';
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
