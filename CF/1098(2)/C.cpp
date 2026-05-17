#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<int,int>;
using v=vector<int>;

int make(int a, int n){
	string as = to_string(a);
	string res;
	for(int i=0; i<n; ++i) res+=as;
	return stoi(res);
}

int solve(){
	int a,n; v d(2);// int &x=d[0], &y=d[1];
	cin>>a>>n>>d[0]>>d[1];
	sort(d.begin(),d.end());
	int &x=d[0], &y=d[1];//x<y
	
	string as=to_string(a);
	if(as.length()<2){
		return min(min(abs(x-a),abs(y-a)),abs(11*x-a));
	}
	
	int les,equ,mor;
	int l=as.length();
	
	les=a-make(y,l-1);
	mor=make(x,l+1)-a;
	
	string es;
	for(int i=0; i<l; ++i){
		int t = as[i]-'0';
		int xd=abs(x-t), yd=abs(y-t);
		int est=min(xd,yd);
		es.push_back(est+'0');
	}
	equ=stoi(es);
	
	return min(min(les,mor),equ);	
}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin>>n;
	for(int i=0; i<n; ++i){
		cout<<solve()<<'\n';
	}
}
