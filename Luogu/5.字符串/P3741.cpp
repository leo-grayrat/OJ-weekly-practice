#include <bits/stdc++.h>
//#define int long long
using namespace std;

void change(char& a){
	a=(a=='V')?'K':'V';
}

int cou(string& inp,int len){
	string ser="VK";
	int n=0;//tem=-1;
	long long pla;
	
	//循环进入点和判断点不一致的时候不要硬整，不如加一小段
	pla=inp.find(ser);
	while(pla!=string::npos){//我和std::string::npos真是一对苦命鸳鸯啊，不要用大小判断，它实际上在longlong中是-1
		//cout<<pla<<'\n';
		n++;pla++;
		pla=inp.find(ser,pla);
	}
	
	return n;
}

int check(string& inp,int len){
	int res=cou(inp,len),tem;
	string ori=inp;
	for(char &a:inp) {
		//不能永久修改！一次只能改一个
		change(a);
		tem=cou(inp,len);
		res=max(tem,res);
		//所以最后要记忆大消除
		inp=ori;
	}
	return res;
}

int main(){
	int len;
	string inp;
	cin>>len>>inp;
	
	cout<<check(inp,len);
}
