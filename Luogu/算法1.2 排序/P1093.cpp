#include <bits/stdc++.h>
using namespace std;
#define int long long

class g{
public:
	int num; int chi; int mat; int eng;
	int all(){
		return chi+mat+eng;
	}
	void read(){
		cin>>chi>>mat>>eng;
	}
	void write(){
//		cout<<num<<all();
		cout<<num<<" "<<all();
	}
};

bool rankG(g& a, g& b){
	if(a.all()!=b.all()) return a.all()>b.all();
	else if (a.chi!=b.chi) return a.chi>b.chi;
	else return a.num<b.num;
}

using v=vector<g>;

signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin>>n;
	v a(n);
	
	for(int i=0; i<n; ++i){
		a[i].num=i+1;//学号不是输入给的
		a[i].read();
	}
	
	sort(a.begin(),a.end(),rankG);//不要用lambda表达式
	// Lambda 表达式其实就是一种“临时用的匿名函数”，可以直接在 sort 函数的参数位置写逻辑
//		 [](g a, g b) { return sort(a,b); });//默认升序
	for(int i=0; i<5; ++i){//只要top5
		if(i!=0) cout<<"\n";
		a[i].write();
	}
}
