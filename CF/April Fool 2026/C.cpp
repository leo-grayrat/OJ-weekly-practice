#include <bits/stdc++.h>
using namespace std;
//#define ll long long

using v=vector<int>;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin>>n;
	for(int i=0; i<n; ++i){
		v a(3); 
		for(auto& ele:a) cin>>ele;
		int bef=a[0]^a[1]^a[2];
		int aft=accumulate(a.begin(),a.end(),0)-*max_element(a.begin(),a.end())-*min_element(a.begin(),a.end());
		cout<<bef-aft<<'\n';
	}
}
