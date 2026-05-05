#include <bits/stdc++.h>
using namespace std;
#define int long long

using v=vector<int>;

v z{1,2};
void zhi(int n){
	if(z.size()>n) return;
	int i=*z.rbegin()+1;
	while(1){
		for(auto& ele : z){
			if(ele==1||i%ele!=0) {
				if(ele==*z.rbegin()){
					//反之，所有数据都印证并非不是质数，那么他就是
					z.push_back(i); return;
				}
				continue;//单个数据无效
			}
			if(i%ele==0) break;//不是质数
			//反之，所有数据都印证并非不是质数，那么他就是
			z.push_back(i); return;
		}
		++i;
	}
}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin>>n;
	for(int i=0; i<n; ++i){
		int m; cin>>m;
		
		cout<<"1"<<" ";
		for(int j=0; j<m-1; ++j){
			zhi(j+1);//混用1/0索引！
			int res=z[j]*z[j+1];
			cout<<res;
			if(j!=m-2) cout<<" ";
			else cout<<'\n';
		}

	}
	
}
