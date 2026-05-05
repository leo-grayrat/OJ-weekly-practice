#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n,q; cin>>n>>q;
	map <int,int> a;
	for(int i=0; i<n; ++i){
		int ele;cin>>ele;
		++a[ele];//创建值对
	}
	int res=0;
	for(int i=0; i<q; ++i){
		map <int,int> b;
		int x; cin>>x;
		if(x==1) {cout<<res<<'\n';continue;}
		res=0;
		for(auto& ele:a){
			int tem=(ele.first)/x;
			b[tem]+=ele.second;
			int tt=tem*ele.second;
			res+=tt;
		}
		cout<<res<<'\n';
		a=b;
	}

	return 0;
}
