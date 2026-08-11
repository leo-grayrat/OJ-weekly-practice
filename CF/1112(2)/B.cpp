#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;
using m=map<int,int>;


void solve(){
	int n,k; cin>>n>>k;
//	v all(k);
	if(k+2>n) {
		cout<<"-1\n";
		return;
	}
	
	string ans;
	
	int ii=(k)/2+1;
	while(ii>0){
		--ii;
		ans+="0";
	}
	
	ii=(k+1)/2+1;
	while(ii>0){
		--ii;
		ans+="1";
	}
	
	ii=(n-(k+1)/2-(k)/2)/2+1;
	while(ii>0){
		--ii;
		ans+="01";
	}
	
	string res=ans.substr(0,n);
	cout<<res<<"\n";
	
	return;

}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin>>n;
	
	for(int i=0; i<n; ++i){
		solve();
	}
	
//	solve();
}
