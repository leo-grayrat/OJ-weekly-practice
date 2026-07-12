#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<int>;

//已力竭

void solve(){
	int n,h; cin>>n>>h;
	v all(n-1); v allori(n);
	
//	cin>>all[0];/*0~all[0]不是有效区间！之后要删掉第一个节点*/
	
////	double len;
//	int bef=0;
//	cin>>bef;
//	
//	for(auto it=all.begin(); it!=all.end(); ++it){
//		cin>>*it; 
////		if(it==all.end()-1) len=*it;
//		*it-=bef;
//		
//	}
////	all.pop_front();
	
	
	//草泥马前缀差不会是吧，行，拆成先取数组再取差
	for(auto it=allori.begin(); it!=allori.end(); ++it){
		cin>>*it; 
	}
	
	for(auto it=all.begin(); it!=all.end(); ++it){
		int diff=it-all.begin();
		*it=allori[diff+1]-allori[diff];
	}
	
	sort(all.begin(),all.end());
//	reverse(all.begin(),all.end());//从大到小，前缀和ikuzo
	
	v sum(n-1); sum[0]=all[0];
	for(int i=1/*0*/; i<n-1; ++i){
		sum[i]=sum[i-1]+all[i];
	}
	
//	int ii=len*n/(double)(n+1);//下界
	int ii=0;
	
	int res=0;
	while(res<h){
		++ii;
		
//		auto fucku = all.begin();
		auto lon=upper_bound(all.begin(), all.end(), ii);
		//找到第一个比cd长的时间间隔
		int usel=lon-all.begin();//会用完的区间数
		
//		res=sum[max(0ll,usel-1)]+(n-usel)*ii;
	if(usel==0) res=(n-usel)*ii;
	else	res=sum[usel-1]+(n-usel)*ii;	
		
		//前面usel个区间会被耗尽，因此是0~usel-1的区间和
		//后面本来有n-usel个区间不会被耗尽、只有ii点伤害//n-1-usel!
		//但是还有最后一次伤害

//		cout<<res<<"||\n";
	}
	
	cout<<ii<<'\n';
}

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin>>n;
	
	for(int i=0; i<n; ++i){
		solve();
	}
	
//	solve();
}
