#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;



signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int x,q; cin>>x>>q;
//	v pas(3),all(5);
	
	//first
	int a1,b1; cin>>a1>>b1;
	v pas{x,a1,b1};
	sort(pas.begin(),pas.end());
//	pas.erase(pas.begin()); pas.pop_back();
	cout<<pas[1]<<'\n';
	
	for(int i=1; i<q; ++i){
		int a,b; cin>>a>>b;
		pas.push_back(a); pas.push_back(b);
		sort(pas.begin(),pas.end());
		pas.erase(pas.begin()); pas.pop_back();
		assert(pas.size()==3);
		cout<<pas[1]<<'\n';
	}
}
