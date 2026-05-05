#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n,m; cin>>n>>m;
	vector<int> a(n), sco(n,0);
	for(auto& ele:a){
		cin>>ele;
	}
	
	for(int i=0; i<m; ++i){
		int l,r;
		cin>>l>>r;
		for(int j=0; j<n; ++j){
			if(l<=a[j]&&a[j]<=r) ++sco[i];
		}
	}
	
	auto res=accumulate(sco.begin(),sco.end(),0)%10007;
	cout<<res;
	return 0;
}
