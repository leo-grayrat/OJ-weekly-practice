#include <bits/stdc++.h>
using namespace std;

void ichi(string &ori){
	string add;
	cin>>add;
	
	ori=ori+add;
	cout<<ori<<'\n';
}

void ni(string &ori){
	int sta, len;
	cin>>sta>>len;
	
	ori=ori.substr(sta,len);
	cout<<ori<<'\n';
}

void san(string &ori){
	int sta;
	string add;
	cin>>sta>>add;
	
	ori.insert(sta,add);
	cout<<ori<<'\n';
}

void yon(string &ori){
	string ser;
	cin>>ser;
	
	long long res=ori.find(ser);//auto 就成 unsigned int 了，你怎么赋值成负数
	if(res==string::npos) res=-1;
	//if(res>1e4) res=-1;
	cout<<res<<'\n';
}

int main(){
	int n, alt;
	string ori;
	cin>>n>>ori;
	
	for(int i=1;i<=n;i++){
		cin>>alt;
		switch (alt) {
		case 1:ichi(ori);break;
		case 2:ni(ori);break;
		case 3:san(ori);break;
		case 4:yon(ori);break;
		}
	}
}
