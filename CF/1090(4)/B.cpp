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
		v a(7);
		for(int j=0; j<7; ++j){
			cin>>a[j];
		}
		int all=accumulate(a.begin(),a.end(),0);
		int rem=*max_element(a.begin(),a.end());
		cout<<-all+2*rem<<'\n';
	}
	
}
