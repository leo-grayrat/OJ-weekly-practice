#include <bits/stdc++.h>
using namespace std;
//#define int long long
using v=vector<char>;

int lef(v& all, int k){
	bool tl=all[k]==*all.begin();
	int res=0;
	for(int i=k; i>0; --i){
		if(all[i]!=all[i-1]) ++res;
	}
	if(!tl) ++res;
	return max(0,res);
}

int rig(v& all, int k){
	bool tl=all[k]==*all.rbegin();
	int res=0;
	int s=all.size();
	for(int i=k; i<s-1; ++i){
		if(all[i]!=all[i+1]) ++res;
	}
	/*
	for(auto i=all.begin()+k-1; i!=all.end()-1; ++i){
		if(*i!=*(i+1)) ++res;
	}*/
	if(!tl) ++res;
	return max(0,res);
}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin>>n;
	for(int i=0; i<n; ++i){
		int a,b; cin>>a>>b;
		v all(a,0);
		for(auto& ele:all) cin>>ele;
		int k; cin>>k; --k;
		int res=max(lef(all,k),rig(all,k));
		cout<<res;
		
		if(i!=n-1) cout<<'\n';
	}
}
