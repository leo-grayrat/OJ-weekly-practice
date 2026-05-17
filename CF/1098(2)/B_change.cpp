#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;

int solve(){
	int n,a,b,k; cin>>n>>a>>b>>k;
//	int dis=min(abs(b-a),abs(n+b-a));
	
	//1.如果只有2/3节点的话，灵梦无论如何都会和蕾米莉亚直接相邻，
		//此时没有绕圈可言，1回合结束
	//2.只有b-a需要取abs，否则abs(b-a)<n+abs(b-a)<abs(n+b-a)恒成立
		//最好还是做到【保证大减小】
	//我在干什么qwq，看了t154654的提交才发现竟然自己这么蠢，不要啊www
	
		int dis=min(abs(b-a),n-abs(b-a));
		
		if(n==2||n==3) return 1;
		else return dis+k;
}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin>>n;
	for(int i=0; i<n; ++i){
		cout << solve() <<'\n';
	}
}
