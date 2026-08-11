#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<int,int>;
using v=vector<ij>;
using m=map<int,int>;


void solve(){
	int k; cin>>k;
//	v all(k);

//	string res;
	
	//就是个栈，内向者选行<=>在栈中添加元素，外向者选行<=>拿走元素
	//内向者最优最窄的行，外向者最优内向者坐过且没坐满的最宽的行，就是拿走栈顶元素
	
	m all; // (宽度, 行数)
	for(int i=1; i<=k; i++){
		int d; cin>>d;
		all[d] = i;
	}
	//红黑树会让他自动按key从小到大排序，正好
	
	v sta; //栈
	string o; cin>>o;
	
	for(int i=0; i<2*k; i++){
		if(o[i]=='0'){
			// 添加元素
			//从map中取
			ij a = *all.begin(); // it 为 pair
			sta.push_back(a);
			//取了删掉map中元素
			all.erase(a.first);
			
			cout<<a.second<<" ";
		}
		else{
			// 取栈顶元素
			ij b = *sta.rbegin();
			sta.pop_back();
			
			cout<<b.second<<" ";
		}
	}
	
}

//void ans(bool res){ 
//	if(res) {cout<<"YES\n"; return;}
//	
//	else {cout<<"NO\n"; return;}
////	cout<<res<<'\n';
//}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
//	int n; cin>>n;
	
//	for(int i=0; i<n; ++i){
//		ans(solve());
//	}
	
	solve();
	return 0;
}
