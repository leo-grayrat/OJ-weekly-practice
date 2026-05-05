#include <bits/stdc++.h>
using namespace std;
//#define int long long

using v=vector<int>;
signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin>>n;
	for(int i=0; i<n; ++i){
		int a; cin>>a;
		for(int j=1; j<=a; ++j){
			cout<<3*a-2*j+2<<" "<<3*a-2*j+1<<" "<<j;
			if(j!=a) cout<<" ";
		}cout<<'\n';
	}
	
}
