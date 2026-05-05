#include <bits/stdc++.h>
using namespace std;
#define int long long
using v=vector<int>;

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin>>n;
	v all(n);
	
	for(int i=0; i<n; ++i){
		cin>>all[i];
	}
	
	sort(all.begin(),all.end());//默认升序
	for(int i=0; i<n; ++i){
		if(i!=0) cout<<" ";
		cout<<all[i];
	}
	/*忏悔：历史遗留问题，模板题不应该用标准库的*/
}
