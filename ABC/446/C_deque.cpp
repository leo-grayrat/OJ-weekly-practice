#include <bits/stdc++.h>
using namespace std;
using egg=deque<int>;

void use(egg& e, int n){
	//从头开始搜索仍然复杂度太高，应该从now-d开始
	//for(auto& ele:e){
	/*for(int i=max(now-d,0);i<e.size();i++){
		if(n<=0) break;
		//如果ele更大那么直接减ele，n更大则减n
		int& ele=e.at(i);//引用！！！
		int tem=min(ele,n);
		n-=tem; ele-=tem;
	}*/
	
	for(auto& ele:e){
		int tem=min(ele,n);
		n-=tem; ele-=tem;
		if(ele==0){
			//有一天的被耗尽了，直接扔掉
			e.pop_front();
		}
		else{
			//那么就是拿完鸡蛋了
			break;
		}
	}
}

void disc(egg& e, int d){
	//int now=e.size()-1;//第几天，但是为了和0索引匹配...
	//我们并没有边扩充e边读取数据！这样不可行
	//day `now`, we should throw day `now-d` and earlier...
	/*
	for(int i=0;i<=now-d;i++){
	e.at(i)=0;
	}*/
	//这样重复丢弃非常耗时！每次丢一天的就行
	int thr=e.size()-d-1;
	//x条有效数据 => 0~x-1 => 应该丢掉第 x-1-d 日的内容
	if(thr>=0) e.pop_front();//e.at(thr)=0;
	
	//其实不如 if(e.size>d) e.pop_front();
}

void each(){
	int n,d;
	cin>>n>>d;//大家好啊，我是换行符
	
	egg a;
	//for(int i=0;i<n;i++) cin>>a.at(i);
	//注意到这里a的大小已经确定了，如果当初ss一下一起读a和b可能会思路更加顺畅
	string tema; 
	cin.ignore();//大家好啊，我是换行符
	getline(cin,tema);
	stringstream ss(tema);
	
	for(int i=0;i<n;i++){
		int tem; ss>>tem;
		a.push_back(tem);
		
		int b; cin>>b;
		use(a,b);
		disc(a,d);
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
