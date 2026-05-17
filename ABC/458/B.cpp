#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<double>;

int diy(int i, int j, int a, int b){
	if(a==1&&b==1) return 0;
	
	if(a==1){
		if((j==0||j==b-1)) return 1;
		else return 2;
	}
	if(b==1){
		if((i==0||i==a-1)) return 1;
		else return 2;
	}
	
	if((i==0||i==a-1)&&(j==0||j==b-1)) return 2;
	else if((i==0||i==a-1)||(j==0||j==b-1)) return 3;
	else return 4;
}
signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int a,b; cin>>a>>b;
	
	for(int i=0; i<a; ++i){
		for(int j=0;j<b;++j){
			cout<<diy(i,j,a,b)<<" ";//<<i<<" "<<j<<"|";
		}
		cout<<'\n';
	}
}
