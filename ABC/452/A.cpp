#include <bits/stdc++.h>
using namespace std;
//#define int long long

using v=vector<int>;
signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string n,m; cin>>n>>m;
	string full=n+m;
	if(full=="17"||full=="33"||full=="55"||full=="77"||full=="99")
		cout<<"Yes";
	else cout<<"No";
}
