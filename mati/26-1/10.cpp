#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	string inp;cin>>inp;
	int res=accumulate(inp.begin(),inp.end(),0);

	cout<<res;
	return 0;
}
