#include <bits/stdc++.h>
using namespace std;
#define int long long

void rig(int& x, int& l, vector<int>& a){
	if(l==0) return;
	
	int m=a.size();int i,j;
	for(i=0; i<m; ++i){
		if(a[i]>=x) break;
		if(i==m-1) return;
	}
	for(j=i; j<m; ++j){
		if(a[j]>=x+l) break;
	}
	if(j==m-1) j=i+1;
	
	int xnew=x+l, lnew=j-i;
	rig(xnew,lnew,a);
	
	for(int k=i; k<j; ++k){
		a[k]=xnew+(k-i);
	}
}

void lef(int& x, int& l, vector<int>& a){
	if(l==0) return;
	
	int m=a.size();int i,j;
	for(i=m-1; i>=0; --i){
		if(a[i]<x) break;
		if(i==0) return;
	}
	for(j=i; j>=0; --j){
		if(a[j]<x-l) break;
	}
	if(j==0) j=i-1;
	
	int xnew=x-l, lnew=i-j;
	lef(xnew,lnew,a);
	
	for(int k=i; k>j; --k){
		a[k]=xnew-(i-k);
	}
}

signed main(){
	int n,m; cin>>n>>m;
	vector<int> a(n);
	for(auto& ele:a){
		cin>>ele;
	}
	sort(a.begin(),a.end());
	
	for(int i=0; i<m; ++i){
		int opt,x,l;
		cin>>opt>>x>>l;
		if(opt==1){
			rig(x,l,a);
		}
		else if(opt==2){
			lef(x,l,a);
		}
	}
	
	for(int i=0; i<n; ++i){
		cout<<a[i];
		if(i!=n-1) cout<<" ";
	}
	
	return 0;
}
