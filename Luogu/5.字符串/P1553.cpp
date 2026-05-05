#include <bits/stdc++.h>
using namespace std;

//using tp=pair<string,string>;
//与其死磕神秘结构体不如直接改原文

void nozero(string &inp){
	/*
	int res=stoi(inp);
	inp=to_string(res);
	*/
	//提到了最大数字是20位，而1e20并不能再cpp中存储，所以我们必须手动排0，不能靠整数自动消除前导零
	int zeros=0;
	for(char scan:inp){
		if(scan!='0') break;
		zeros++;//这个变量就是前导0的数量
	}
	inp.erase(0,zeros);
}

void integer(string& inp){
	//600.048->6.480，所以你还得处理下反转前的前导0
	nozero(inp);
	reverse(inp.begin(),inp.end());
	nozero(inp);
		//但是你不能把就是0的输入日了！！！
	if(inp=="") inp="0";
}

void demical(string& p1, string& p2){
	
	integer(p1);
	integer(p2);
}

void percent(string& inp){
	inp.pop_back();//消除%
	integer(inp);
	inp+="%";//再加回去
}

int main(){
	string inp,fir,sec;
	cin>>inp;
	
	//后来发现cpp中没有支援string的strtok这样直接分割字符串的函数，只能自己pushback+substr，所以还是用流思想更好
	auto dem=inp.find("."),fra=inp.find("/"),per=inp.find("%");
	if(dem!=string::npos){
		stringstream ds(inp);
		getline(ds,fir,'.');
		getline(ds,sec);
		demical(fir,sec);
		
		cout<<fir<<"."<<sec;
	}
	else if(fra!=string::npos){
		stringstream fs(inp);
		getline(fs,fir,'/');
		getline(fs,sec);
		demical(fir,sec);
		cout<<fir<<"/"<<sec;
	}
	else if(per!=string::npos){
		percent(inp);
		cout<<inp;
	}
	else{
		integer(inp);
		cout<<inp;
	}
}
