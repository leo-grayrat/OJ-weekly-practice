#include <bits/stdc++.h>
#define int long long
using namespace std;

void pre(string &cha){
	for(auto &alp:cha){
		if(alp>='A'&&alp<='Z') alp-=('A'-'a');
	}
}

bool che(string &ori, string &wrd, int pla){ //你搜出来的位置是单词吗
	int tl=wrd.length()+pla; 	//这个指的是单词后一位的位置
	int len=ori.length();		//长度和索引并非对应关系
	bool bef,aft;
	
	//前面应该是空格，除非你是第一个单词
	if(pla==0) 	bef=true;
	else		bef=(ori[pla-1]==' ');
	//后面も，除非你是最后一个单词
	if(tl==len) aft=true;
	else		aft=(ori[tl]==' ');
	
	return bef&&aft;
}

using duo = pair<int,int>;

duo ser(string &ori, string &wrd){
	int fir=-1,tem=0,cou=0;
	duo fail(0,0);
	/*
	//第一次搜索单独处理，因为要给出第一次搜到的位置
	fir=ori.find(wrd);
	//如果找不到
	if(fir==string::npos) return fail; //注意下npos是longlong型
	
	//如果找得到
	//cou++; 注意数次数问题
	tem=fir;
	*/
	//第一次难道不需要验证是不是单词吗？不能只顾第一次找到
	
	bool hajimemashite=true;
	
	//少了个从0开始find
	tem=ori.find(wrd);
	
	while(tem!=string::npos){//至此知道成功了一个循环/成功了初始值...吗？
		//还要检查是不是单词，前面只是知道找到了匹配字母序列
		if(che(ori,wrd,tem)) cou++;//如果验证通过，那么就真的找到了
		
		//新加！第一次不能单列，只能内部判断了
		//！！！“第一次”必须只能出现一次！！！
		if(cou==1&&hajimemashite) {
			fir=tem;
			hajimemashite=false;
		}
		
		tem=ori.find(wrd,tem+1);
	}
	//输出结果
	//此刻仍有可能fail，即所有找到的都不是单词，此时cou=0
	//不过没有必要特殊处理，我们验证的标准是cou==0就算失败
	duo res(cou,fir);
	return res;
}

signed main(){
	//获取数据
	string ori,wrd;
	cin>>wrd;
	getline(cin,ori);//换行符！
	getline(cin,ori);//获取一整行
	
	//预处理，解决大小写问题
	pre(wrd);
	pre(ori);
	
	//主要部分
	duo res=ser(ori,wrd);
	
	//处理输出结果
	if(res.first==0) cout<<-1;//失败
	else cout<<res.first<<" "<<res.second;
	
	return 0;
}
