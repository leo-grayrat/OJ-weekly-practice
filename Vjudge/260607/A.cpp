#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<string>;


void solve(){
	string ori; cin>>ori;
	int num=0; int fir=-1, fin=-1;
	for(int i=0; i<ori.length(); ++i){
		if(ori[i]=='0') continue;
		
		if(fir==-1) fir=i;
		fin=i;
		++num;
	}
	int res=fin-fir-num+1;
	if(fin==fir) res=0;
	cout<<res<<'\n';
}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin>>n;
	
	for(int i=0; i<n; ++i){
		solve();
	}
}
