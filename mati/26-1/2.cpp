#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; ++i){
		cin>>a[i];
		if(i!=0){
			a[i]=min(a[i-1],a[i]);
		}
		cout<<a[i];
		if(i!=n-1) cout<<" ";
	}

	return 0;
}
