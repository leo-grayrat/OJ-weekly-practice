#include <bits/stdc++.h>
using namespace std;
#define int long long

using vi=vector<int>::iterator;
int each(vi& ita, vi& itb, vi& itc){
	++ita;
	return (*ita)*(*itb)*(*itc);
}

int big3(int& a, int& b, int& c){
	if(a<=b&&a<=c) return 0;
	else if(b<=a&&b<=c) return 1;
	else return 2;
}

int whole(vi ita, vi itb, vi itc, int& who){
	vector<int> n(3);
	n[0]=each(ita,itb,itc);
	n[1]=each(itb,itc,itc);
	n[2]=each(itc,itb,ita);
	who=big3(n[0],n[1],n[2]);
	return n[who];
}

void more(vi& ita, vi& itb, vi& itc, int& who){
	switch (who) {
	case 0:
		++ita;
		break;
	case 1:
		++itb;
		break;
	case 2:
		++itc;
		break;
	}
}

signed main(){
	int t;	cin>>t;
	for(int times=0;times<t;++times){
		int n,m; cin>>n>>m;
		vector<int> a(n),b(n),c(n);
		for(auto& ele:a)cin>>ele;
		for(auto& ele:b)cin>>ele;
		for(auto& ele:c)cin>>ele;
		
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		sort(c.begin(),c.end());
		
		auto ita=a.begin(),itb=b.begin(),itc=c.begin();
		int fres=(*ita)*(*itb)*(*itc);
		cout<<fres;
		
		for(int i=1; i<m; ++i){
			cout<<" ";
			int who;
			int res=whole(ita,itb,itc,who);
			more(ita,itb,itc,who);
			cout<<res;
		}
		cout<<'\n';
	}
	
	return 0;
}
