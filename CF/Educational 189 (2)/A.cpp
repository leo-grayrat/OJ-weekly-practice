#include <bits/stdc++.h>
using namespace std;
#define int long long


//using v=vector<int>;

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin>>n;
//	v a(n);
	for(int i=0; i<n; ++i){
		int a,b;
		cin>>a>>b;
		string res = b==2*a ? "NO" : "YES";
		cout<<res<<'\n';
	}

}
