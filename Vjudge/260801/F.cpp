#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;
using m=map<int,int>;

int solve(){
	int k; cin>>k;
	
	//先找到所有正数之和，如果不成立则
	//开始看删去最小奇数或者加上最大负数
	
//	v pos,neg; //positive negative antlers(无端)
	v all; //把正负都取绝对值就行了，然后还是减最小奇数
	int res=0;
	for(int i=0; i<k; i++){
		int t; cin>>t;
		if(t>0) 		{
						all.push_back(t);
						res+=t; //但是还是要数正数之和
		}	
		else if(t<0) 	all.push_back(-t);
		else 			continue;
	}
		
//	int res=accumulate(pos.begin(),pos.end(),0);
	
	if(res&1) return res;
	
	sort(all.begin(), all.end());
	for(auto& ele:all){
		if(ele&1){
			res-=ele;
			break;
		}
	}
	return res;
}

void ans(int res){ 
//	if(res) {cout<<"YES\n"; return;}
//	
//	else {cout<<"NO\n"; return;}
	cout<<res<<'\n';
}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
//	int n; cin>>n;
//	
//	for(int i=0; i<n; ++i){
//		ans(solve());
//	}
	
	ans(solve());
	return 0;
}
