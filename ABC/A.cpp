#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<string>;

int solve(){
	string ori; cin>>ori;
	char a=ori[0];
	
	v all{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	//统一初始化daisuki
	
	for(int i=0; i<all.size(); ++i){
		size_t b=all[i].find(a);
		if(b!=string::npos) return i+2;
	}
	return 0;
}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin>>n;
	
//	int res=0;
	//不是累加，只是依次显示而已
	for(int i=0; i<n; ++i){
//		res+=solve();
		cout<<solve();
	}
	
//	cout<<res;
//	solve();
}
