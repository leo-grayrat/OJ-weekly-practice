#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;

void solve(){
	int n; cin>>n;
	v all(3);
	for(int i=0; i<n; ++i){
		int t; cin>>t;
		all[t%3]++;
	}
	int r0=all[0],
	r12=min(all[1],all[2]),
	r3n=(max(all[1],all[2])-r12)/3;
	cout << r0+r12+r3n<<'\n';
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
