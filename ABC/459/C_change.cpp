#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n,q; cin>>n>>q;
	v all(n,0);
	for(int i=0; i<q; ++i){
		int t; int a; cin>>t>>a;
		
		if(t==1){
			++all[a-1];//1索引
		}
		if(t==2){
			int tar=*min_element(all.begin(),all.end())+a;
			int res=0;
			for(auto &ele:all){
				if(ele>=tar) ++res;
			}
			cout<<res<<'\n';
		}
	}
}
