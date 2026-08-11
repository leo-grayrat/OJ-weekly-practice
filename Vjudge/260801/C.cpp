#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;
using m=map<int,int>;

v z{2};

bool pri(int k){
	if(k==1) return true;
	
	int up=sqrt(k);
	for(auto& ele:z){
		if(ele>up) break;
		if(k%ele==0) return false;
	}
	z.push_back(k);
	return true;
}

int solve(){
	int d; cin>>d;
	
	//就是找三个质数（首个为1）, 至少间隔d
	//答案就是质数Ⅱ*Ⅲ
	
	int a[3]; a[0]=1;
	for(int i=1; i<=2; i++){
		int n=a[i-1]+d;
		while(!pri(n)) ++n;
		a[i]=n;
	}
	
	return a[1]*a[2];
}

void ans(int res){ 
//	if(res) {cout<<"YES\n"; return;}
//	
//	else {cout<<"NO\n"; return;}
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
	
//	ans(solve());
	return 0;
}
