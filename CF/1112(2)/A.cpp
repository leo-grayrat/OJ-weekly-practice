#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;
using m=map<int,int>;


bool solve(){
	int k; cin>>k;
//	v all(k);
	
	if (k%2!=0) {
		string wasted;
		getline(cin,wasted);
		getline(cin,wasted);
		return 0;
	}
	
	int ii=(k)/2;
	v odd(ii), even(ii);
	
	while(ii>0){
		--ii;
		int &a=odd[ii], &b=even[ii];
		cin>>a>>b;
	}
	
//	if (k%2!=0) return 0;
	
	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end());
	
	
	return odd[0]>(even[k/2-1]+1);
}

void ans(bool inp){ 
	if(inp) {cout<<"yes\n"; return;}
	
	else {cout<<"no\n"; return;}
}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin>>n;
	
	for(int i=0; i<n; ++i){
		ans(solve());
	}
	
//	solve();
	return 0;
}
