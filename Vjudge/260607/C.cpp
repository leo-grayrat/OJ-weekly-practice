#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;


int solve(){
	v a(3,0);
	for(auto& ele : a) cin>>ele;
	int f=a[1]-a[0], s=a[2]-a[1];
	if(f>s) return f-s;
	else if(f==s) return 0;
	else{
		if ((s-f)%2==0) return (s-f)/2;
		else return (s-f)/2+2;
	}
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
