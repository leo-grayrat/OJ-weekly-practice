#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<int,int>;
using v=vector<int>;

int make(int a, int n){
	string as = to_string(a);
	string res;
	for(int i=0; i<n; ++i) res+=as;
	return stoll(res);//stoi(res);
}

//错误二：位数相同（equ）时未考虑高位借位/进位
//这种逐位贪心的思想也是错的。
//反例：假设 \(a = 41\)，\(x = 3, y = 9\)。
//逐位选择最接近的数字：\(4\) 最接近 \(3\)，\(1\) 最接近 \(3\)，拼出 \(33\)。
//实际上，由 \(3\) 和 \(9\) 组成的两位数中，最接近 \(41\) 的是
//……\(39\)（差值为 \(2\)），而不是 \(33\)（差值为 \(8\)）。
//因为低位的选择会受到高位大小关系的影响。

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
	equ=stoll/*stoi*/(es);
	
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
