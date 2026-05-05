#include <bits/stdc++.h>
using namespace std;
#define int long long

int cal(int inp){
	return inp*inp*inp;
}

bool def(int res){
	res=cal(res);
	return (res%10)==3;
}

signed main(){
	int res=0;
	for(int i=1; i<=2025; ++i){
		res+=def(i);
	}
	cout<<res;
}
