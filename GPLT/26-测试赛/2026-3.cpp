#include <bits/stdc++.h>
using namespace std;
#define ll long long

int alph(char one){
	switch (one) {
	case 'x':
		return 1;
		break;
	case 'j':
		return 2;
		break;
	case 't':
		return 3;
		break;
	case 'u':
		return 4;
		break;
	default:
		return 0;
		break;
	}
}

int each(string& inp){
	int sta=1;
	if(alph(inp.at(0))!=1) return false;//出师太着急，直接到了jtu
	for(auto& ele:inp){
		int now=alph(ele);
		if(sta==now||now==sta+1) sta=max(sta,now);
		else return false;
	}
	if(sta==4) return true;
	else return 2;//有潜力的
}

int sons(string& inp){
	int cou=0;
	for(auto it=inp.begin(); it!=inp.end()-3; ++it){
		//bool hajimaruyo=false;
		for(auto jt=it+4; jt!=inp.end()+1; ++jt){
			string sub(it,jt);
			if(each(sub)==1){
				//hajimaruyo=true;
				++cou;
			}
			else if(each(sub)==0){break;
				//if(hajimaruyo) break;
			}
		}
	}
	return cou;
}

int main(){
	ios::sync_with_stdio(false); // 关闭 C 和 C++ 的同步
	cin.tie(nullptr);            // 解绑 cin 与 cout
	cout.tie(nullptr);           // 解绑 cout 与 cin
	
	int n; cin>>n;
	string inp; cin>>inp;
	cout<<sons(inp);
}
