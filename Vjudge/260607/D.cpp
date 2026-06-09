#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;


class bus{
public:
	int t;
	int d;
	int cal(int tg){
//		double b=(tg-t)/(double)d;
//		int br=b;
////		int b=(tg-t)/d; int br=b;
////		int diff=tg-t-d*b;
////		if(diff!=0) ++br;
//		
//		if(br<0) return t-tg;
//		else{
//			int next=t-tg-br*d;
//			if(next<0) next+=d;
//			return next;
////			int next=t-tg-br*d; return next;
//		}
		int tt=t;
		while(tt<tg) tt+=d;
		return tt;
	}
//	int res;
};

using v=vector<bus>;
using vi=vector<int>;

int solve(){
	int n,t; cin>>n>>t;
	v all(n); vi res;
	for(auto& ele:all){
		cin>>ele.t>>ele.d;
		res.push_back(ele.cal(t));
	}
	int mini=min_element(res.begin(),res.end())-res.begin();
	return mini+1;
}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
//	int n; cin>>n;
//	
//	for(int i=0; i<n; ++i){
//		solve();
//	}
	cout<<solve();
}
