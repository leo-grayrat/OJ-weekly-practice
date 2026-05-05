#include <bits/stdc++.h>
using namespace std;

int cal(string inp){
	int res=1;
	for(auto ele:inp){
		int tem=ele-'A'+1;
		res*=tem;
	}
	return res;
}

int main(){
	string suisen,team;
	cin>>suisen>>team;
	int sui=cal(suisen)%47, tea=cal(team)%47;
	
	string choose=sui==tea?"GO":"STAY";
	cout<<choose;
}
