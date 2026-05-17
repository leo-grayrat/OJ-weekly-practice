#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

using ij=pair<double,double>;
using v=vector<double>;



signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	string inp; cin>>inp;
	int res=0;
	
	for(int i=0; i<inp.length(); ++i){
		if(inp[i]=='C'){
			res+=min(i+1,inp.length()-i);
		}
	}
	
	cout<<res;
}
