#include <bits/stdc++.h>
using namespace std;

//先得处理首字母大写问题
void pre(string &inp){
	bool a=inp.at(0)>='A', b=inp.at(0)<='Z';
	if(a&&b) inp.at(0)-=('A'-'a');
}

int input(const string& inp){
	if(inp=="zero") return 0;
	if(inp=="a"||inp=="one"||inp=="another"||inp=="first") return 1;
	if(inp=="both"||inp=="two"||inp=="second") return 2;
	if(inp=="third"||inp=="three") return 3;
	if(inp=="four") return 4;
	if(inp=="five") return 5;
	if(inp=="six") return 6;
	if(inp=="seven") return 7;
	if(inp=="eight") return 8;
	if(inp=="nine") return 9;
	if(inp=="ten") return 10;
	if(inp=="eleven") return 11;
	if(inp=="twelve") return 12;
	if(inp=="thirteen") return 13;
	if(inp=="fourteen") return 14;
	if(inp=="fifteen") return 15;
	if(inp=="sixteen") return 16;
	if(inp=="seventeen") return 17;
	if(inp=="eighteen") return 18;
	if(inp=="nineteen") return 19;
	if(inp=="twenty") return 20;
	else return -1;
}

string calcu(const int& inp){
	if(inp==-1) return "";//不是数字
	
	int res = (inp*inp)%100;
	string resst=to_string(res);
	
	//注意！排序的时候0x当作两位数，不能忽略首位数
	if(resst.length()==1) resst="0"+resst;
	
	return resst;
}

string secre(vector<string> inp){
	//不止三个数字可能！
	/*
	auto maxp = max_element(inp.begin(), inp.end());
	auto minp = min_element(inp.begin(), inp.end());
	// 返回迭代器，即指针
	
	int maxi=*maxp,mini=*minp;
	int midi=accumulate(inp.begin(),inp.end(),0)-maxi-mini;
	
	int res=mini*1e4+midi*1e2+maxi;
	*/
	
		//for(auto ele:inp) cout<<ele<<" ";
		//cout<<"|";
	
	sort(inp.begin(),inp.end());//从小到大
	
	string res="";
	for(auto ele:inp) res+=ele;
	
	//去起始0
	//转数字再转回来或许有用
	//前提是不是空字符串	
	//if(res!="") res=to_string(stoi(res));
		//真的吗？这样分分钟溢出
	
	int count=0;
	for(auto ele:res){
		if(ele=='0') count++;
		else break;
	}	//cout<<res<<" "<<count<<'\n';
	res.erase(0,count); 
	return res;
}

int main(){
	vector<string> inp;
	for(int i=0;i<6;i++){
		string tem;
		cin>>tem;
		pre(tem);
		// 错误访问！ inp.at(i) = calcu ( input (tem) );
		inp.push_back(calcu ( input (tem) ));//向后端添加，或者在此之前声明时声明6元素的vector
	}
	
	string res=secre(inp);
	if(res!="") cout<<res;
	else cout<<"0";
}
