#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<double>;
double cal(ij a, ij b){
	auto [ai,aj]=a;
	auto [bi,bj]=b;
//	return ai*bi+aj*bj-ai*bj-aj*bi;
	//是和共轭之积，也就是模长平方
	return ai*bi+aj*bj;
}
int times(int a){
	int ans=1;
	for(int i=0; i<a; ++i){
		ans*=2;
	}
	return ans;
}

signed main(){
	int a;	cin>>a;
	int n=times(a);
	v all(n);
	for(int i=0; i<n; ++i){
		ij t; cin>>t.first>>t.second;
		all[i]=cal(t,t);//i(10进制)状态的可能性
	}
	for(int i=0; i<a; ++i){
		double res=0.0;
//		auto check=1<<(a-i-1);//从最左位的位掩码开始
		//并不是
		auto check=1<<i;
		for(int j=0; j<n; ++j){
			if(j&check) res+=all[j];
		}
		cout<<1-res<<" "<<res<<'\n';
	}
}
