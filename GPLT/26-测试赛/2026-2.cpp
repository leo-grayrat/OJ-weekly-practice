#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll zero=0;

ll each(vector<ll>::iterator sta, vector<ll>::iterator tal, ll now){
	int dis=tal-sta;
	if(dis==1||dis==2) return now+max(zero,*sta);
	else{
		//ll sto=now;
		
		//sta+=2;
		
		//if(*sta<0) sto=now;
		ll bef=each(sta+2,tal,now+*sta);
		//++sta;
		//if(*sta<0) sto=now;
		//ll aft=each(sta,tal,now+*sta);
		return max(bef,now);
	}
}

int main(){
	int n; cin>>n;
	//ll best=0; bool meeh=false;//如果跳过一回合，那么meeh就为真
	vector<ll> all(n);
	for(auto & ele : all) cin>>ele;
	ll resa=each(all.begin(),all.end(),zero);
	ll resb=each(all.begin()+1,all.end(),zero);
	cout<<max(resa,resb);
}
