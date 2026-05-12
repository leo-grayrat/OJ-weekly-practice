#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<double>;



signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin>>n;
	for(int i=0; i<n; ++i){
		int n,k; cin>>n>>k;
		int c=n+k;
		//n-2个1即可，剩下得 (x-1)(y-1)=n+k-1
		for(int j=0; j<n-2; ++j) cout<<"1 ";
		cout<<"2 "<<c<<'\n';
	}
}
