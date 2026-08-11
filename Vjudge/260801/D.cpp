#include <bits/stdc++.h>
using namespace std;
#define int long long

using v=vector<string>;
using ij=pair<bool,v>;
//using m=map<int,int>;

ij solve(){
	int k; cin>>k;
	v all(k);
//	string o; cin>>o;
//	string res;
	
	for(auto& ele:all){
		cin>>ele;
	}
	
	sort(all.begin(),all.end(),
		 [](const string &a, const string &b) {
			 return a.size() < b.size();
		 });
	//sort默认按字典序排序
	//我们要按长度排序
	//耍一耍lambda
	
	for(int i=1; i<k; i++){		
		size_t pos=all[i].find(all[i-1]);
		if(pos==string::npos) return make_pair(false,all);
	}
	
	return make_pair(true,all);
}

//void ans(bool res){ 
void ans(ij res){ 
	if(res.first) {
		cout<<"YES\n";
		
		for(auto& ele:res.second){
			cout<<ele<<"\n";
		}
		
		return;
	}
	
	else {cout<<"NO"; return;}
//	cout<<res<<'\n';
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
