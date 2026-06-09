#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<string>;


void solve(){
	string ori; cin>>ori;
	map<char,int> all;
	
	for(auto& ele : ori){
		++all[ele];
	}
	
	sort(all.begin(),all.end(),[]{int a,b; return a<b;});
//你怎么能sort图呢？
	//算法是按出现次数排列字符，如aaaabbbccd，然后前后切成两半如aaaab bbccd，然后插空放置
	//待补充，不是abc过两题什么的太傻逼了，但是每次都是到比赛前都还有事情要处理，最后一边写题一遍搞事最后往往刷手机去了……
	//STAY FOCUSED
}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin>>n;
	
	for(int i=0; i<n; ++i){
		solve();
	}
}
