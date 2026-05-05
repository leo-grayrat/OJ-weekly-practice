#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n,m; cin>>n>>m;
	vector<int> a(n); int sco=0;
	for(auto& ele:a){
		cin>>ele;
	}
	sort(a.begin(),a.end());
	int ma=*a.rbegin(), mi=*a.begin();
	int zero=0;
	
	for(int i=0; i<m; ++i){
		int l,r;
		cin>>l>>r;
		l=max(l,mi), r=min(r,ma);
		if(l>r) continue;
		
		int dsq=ma-r+l-mi;
		
		//int qlf=n-dsq;
		sco+=(dsq%10007);

	}
	cout<<sco%10007;
	return 0;
}
