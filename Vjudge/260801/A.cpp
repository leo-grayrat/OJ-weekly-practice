#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;
using m=map<int,int>;


string solve(){
	int k; cin>>k;
//	v all(k);
	string o; cin>>o;
	string res;
	
	int ori=0;
	for(auto& ele:o){
		int now=ele-'0';
		int add;
		
		switch (ori) {
		case 0:
			add=1;
			break;
		case 1:
			add=now?1:0;
			break;
		case 2:
			add=now?0:1;
			break;
		}
		
		res.push_back(add+'0');
		
		ori=now+add;
	}
	
	return res;
}

void ans(string res){ 
//	if(inp) {cout<<"yes\n"; return;}
//	
//	else {cout<<"no\n"; return;}
	cout<<res<<'\n';
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
