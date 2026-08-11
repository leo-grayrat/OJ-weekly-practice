#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;
using m=map<int,int>;

int x(int a, int b){
	return a*a*a+a*a*b+a*b*b+b*b*b;
}

int solve(){
	int n; cin>>n;
	
	if(n==0) return 0;
	
	//不妨设a>=b，因为ab对称
	//显然a=b时有固定a时的最大
	//最小的a ~ a=b时至少有X=4a^3>=n
	//最大的a ~ b=0时X=a^3>=n的最小a
	
	long double low = pow(n/4, 1.0L/3.0); //L为longdouble
	long double upp = pow(n, 1.0L/3.0);
	//low=amin<=a<=upp<=amax
	
	int res=LLONG_MAX;
	
	for(int i=low;i<=upp+1;i++){
//		for(int j=0;j<=i;j++){
//			if(x(i,j)>=n) break;
//		}
		//双层循环很有意思？
		//试试二分，单增肯定要二分啊
		
		int lb=-1, ub=i; //左开右闭
		while(ub-lb>1){
			int mid=(lb+ub)/2;
			if(x(i,mid)>=n)	ub=mid;
			else 			lb=mid;
		}
		//结果时候ub=1+lb
		//但是由于浮点什么的，这里可能出现不符合的情况		
		int tem=x(i,ub);
		if(tem<n)	continue;
		else 		res=min(tem,res);
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
