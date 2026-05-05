#define _CRT_SECURE_NO_WARNINGS 1

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n, cou=0; cin>>n;
	vector<int> a(n); vector<int> b(n);
	for(int i=0; i<n; ++i){
		cin>>a[i]>>b[i];
		if(b[i]>=a[i]) cou++;
	}
	
	cout<<cou<<" "<<n-cou;
	return 0;
}
