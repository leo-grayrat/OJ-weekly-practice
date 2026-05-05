#include <bits/stdc++.h>
using namespace std;
//#define int long long

using v=vector<int>;
signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n,m; cin>>n>>m;
	v a(m,0), b(m,0);
	
	for(int i=0; i<n; ++i){
		int fir,sec;
		cin>>fir>>sec;
		++a[fir-1]; ++b[sec-1];
	}
	
	for(int i=0; i<m; ++i){
		cout<<b[i]-a[i]<<'\n';
	}
}
