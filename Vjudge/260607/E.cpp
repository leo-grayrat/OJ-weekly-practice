#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;


unsigned long long solve(){
	int n;
	cin>>n; v all(n);
	unsigned long long res=0; int minuc=0;
	unsigned long long minu=string::npos;
	
	for(auto& ele:all){
		int tem; cin>>tem;
		if(tem<0) {
			tem=-tem;
			++minuc;
		}
		
		if(tem<minu) minu=tem;
		
		res+=tem;
	}
	
	if(minuc%2==0) return res;
	else return res-2*minu;
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
	cout<<solve();
}
