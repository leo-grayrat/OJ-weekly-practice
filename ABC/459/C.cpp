#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n,q; cin>>n>>q;
	v all(n,0);
	for(int i=0; i<q; ++i){
		int t; int a; cin>>t>>a;
		
		if(t==1){
			++all[a-1];//1索引
		}
		if(t==2){
			int tar=*min_element(all.begin(),all.end())+a;
			
			v tem=all;
			sort(tem.begin(),tem.end());//先从小到大
			auto it=lower_bound(tem.begin(),tem.end(),tar);
				//第一个>=target的位置
			int res=tem.end()-it;
			cout<<res<<'\n';
		}
	}
	
}
