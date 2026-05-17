#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<double>;



signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	string inp; cin>>inp;
	int n; cin>>n;
	
	inp.erase(0,n);
	for(int i=0; i<n; ++i){
		inp.pop_back();
	}
	
	cout<<inp;
}
