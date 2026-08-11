#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;
using m=map<int,int>;


bool solve(){
	int k; cin>>k;
//	v all(k);
//	string o; cin>>o;
//	string res;
	
	//用下现学的位运算
	while(!(k&1)) k=k>>1;
	
//	int up=sqrt(k);
//	for(int i=3;i<=up;i++){
//		if(k%i==0) return true;
//	}
//	return false;
	
	//奇数能被自己整除
	//偶数若有2以外的因子也不行
	//那不就是求是不是2的幂吗？？？
	if(k==1) return false;
	else return true;
}

void ans(bool res){ 
	if(res) {cout<<"YES\n"; return;}
	
	else {cout<<"NO\n"; return;}
//	cout<<res<<'\n';
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
