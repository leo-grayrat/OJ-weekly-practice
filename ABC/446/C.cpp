#include <bits/stdc++.h>
using namespace std;
using egg=vector<int>;

void use(egg& e, int n, int now, int d){
	//从头开始搜索仍然复杂度太高，应该从now-d开始
	//for(auto& ele:e){
	for(int i=max(now-d,0);i<e.size();i++){
		if(n<=0) break;
		//如果ele更大那么直接减ele，n更大则减n
		int& ele=e.at(i);//引用！！！
		int tem=min(ele,n);
		n-=tem; ele-=tem;
	}
}

void disc(egg& e, int now, int d){
	//int now=e.size()-1;//第几天，但是为了和0索引匹配...
		//我们并没有边扩充e边读取数据！这样不可行
	//day `now`, we should throw day `now-d` and earlier...
	/*
	for(int i=0;i<=now-d;i++){
		e.at(i)=0;
	}*/
	//这样重复丢弃非常耗时！每次丢一天的就行
	int thr=now-d;
	if(thr>=0) e.at(thr)=0;
}

void each(){
	int n,d;
	cin>>n>>d;
	
	egg a(n,0);
	for(int i=0;i<n;i++) cin>>a.at(i);
	
	//对给出用量之后，就可以不光纯读取数据了，可以直接开始计算了
	for(int i=0;i<n;i++){
		int b; cin>>b;
		use(a,b,i,d);
		disc(a,i,d);
	}
	
	//计算完成之后，总蛋数是a的和
	int res=accumulate(a.begin(),a.end(),0);
	cout<<res<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t; cin>>t;
	for(int i=0; i<t; i++) each();
}
