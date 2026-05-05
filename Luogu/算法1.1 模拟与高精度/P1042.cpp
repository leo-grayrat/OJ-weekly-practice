#include <bits/stdc++.h>
using namespace std;

using sco=pair<int,int>;//局得分
/*
 * using gam=pair<bool,sco>;//前面true表示主队赢下本局
 * using mat=vector<gam>;//一场比赛由很多局组成
 */
//输出只需要局得分，末尾的"1:1"之类的并非总比分，只是还没结束的那一局的结果
using mat=vector<sco>;//很多局的得分集合

bool res(const char& inp){
	bool winorlose=inp=='W'?true:false;
	return winorlose;
}

bool win(const sco& rou, int ii){
	//实际上不用知道谁赢了，只需要知道有人赢了没有就行了
	int sen=max(rou.first,rou.second),jun=min(rou.first,rou.second);
	if(sen<ii) 			return false;//没到11/21分
	else if(sen-jun<2) 	return false;//没有拉开2分
	else 				return true; //获胜
}

auto ful(const string& inp, int ii){
	mat game;//总得分表
	sco rou{0,0};//每局现存的得分
		//记得初始化！！！
	for(auto ele:inp){
		if(ele=='E') break;//忽略E及以后的部分
		
		if(res(ele)) ++rou.first;
		else ++rou.second;
		
		//检查胜负
		if(win(rou,ii)){
			//有人赢了，那么要归零并存档这局结果
			game.push_back(rou);
			rou.first=0, rou.second=0;
		}
	}
	//读取结束，不要忘了最后一局（未完成）
	//if(rou.first||rou.second){
		//如果全为0则失败，即最后一局刚好结束
		game.push_back(rou);
	//}
		//草泥马，0:0也要写
	return game;
}

void dis(mat game){
	for(auto ele:game){
		cout<<ele.first<<":"<<ele.second<<'\n';
	}
}

int main(){
	string tem,all;
	while(getline(cin,tem)) {
		/*
		 * //请注意，这样会读取换行符，会出问题
		 * if(tem!="") tem.pop_back();//砍掉换行符，前提是非空
		 */
		//并非...消耗换行不等于读取换行
		if(tem!=""){
			if(tem.back()=='\r') tem.pop_back();
			/* 全WA也是有了...
				这段代码在读取输入时使用了 getline，它会将每行末尾的回车符 '\r'（如果输入文件是 Windows 格式）也读入字符串中。
				这些 '\r' 不是 'W'、'L' 或 'E'，但在后续处理中会被 res 函数当作 'L'（因为不是 'W'）处理，从而错误地增加对手的得分，导致所有测试点结果错误。
				而样例输入可能是 Unix 格式（无 '\r'），所以能够通过。
				此外，空行也可能包含 '\r' 导致同样的问题。这是代码的主要隐患。
			*/
			//woc 智障deepsuck竟然猜对一次了
		}
		all+=tem;
	}
	
	auto eleven=ful(all,11);
	dis(eleven);
	//有一行空行
	cout<<'\n';
	auto twelve=ful(all,21);
	dis(twelve);
	
	return 0;
}
