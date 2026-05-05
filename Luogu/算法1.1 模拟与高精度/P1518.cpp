#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

using fore=array<array<char,10>,10>;
//作为对照，vector<vector<int>> matrix(3, vector<int>(4, 0));
//因为array大小固定，所以要额外声明
using loca=pair<int,int>;
auto scan(){
	//char fore[10][10]
	//你说的对但是std::array 是 C++ 标准库中的一个模板类，用于表示固定长度的数组...
	fore f; int x=0;
	loca C,F;
	for(auto &elem:f){
		int y=0;
		for(auto &each:elem){
			char inp;
//			cin.get(each);
			//换行符我cnm,,,
			//事实上你对象是char时cin一次就只读一个字符，所以没有必要cin.get
			//而且如果有\r\n这种恶心玩意怎么办？cin大人可是能跳过空白字符的哦~
//			cin.get(inp);
//			if(inp=='\n') cin.get(inp);//是换行就多读一位
			cin>>inp;
			each=inp;
			if(each=='F') F=make_pair(x,y);
			if(each=='C') C=make_pair(x,y);
			y++;
		}
		x++;
	}
	return make_tuple(f,F,C);
}

bool empt(char& inp){
	bool res=inp=='*'?false:true;//不是障碍物就行
	return res;
}

void turn(int& dir){
	//0上，1右，2下，3左
	dir = dir>=3 ? 0 : dir+1;
}

auto move(loca &A, int& dir){
	auto [x,y]=A; 
	
	switch (dir) {
	case 0: --x;break;
	case 1: ++y;break;
	case 2: ++x;break;
	case 3: --y;break;
	}
	
	loca res=make_pair(x,y);
	return res;
}

bool rche(loca &A){//range check
	int ma=max(A.first,A.second),mi=min(A.first,A.second);
	if(ma>9||mi<0) return false;
	else return true;
	//一定要先rche再mche，否则越界有你好果子吃的
	//当然似乎trycatch也可以...
}

bool mche(fore &f, loca &A, int& dir){//move check
	auto [x,y]=A;
	auto plac=f[x][y];
//	if(empt(plac)) return true;
//	else return false;
	return empt(plac);
}

void mful(fore &f, loca &A, int& dir){//move full procedure
	auto m=move(A,dir);
//	bool rc=rche(A);
	bool rc=rche(m);//我真是服了，暂存待检查的参数到底是谁
	if(!rc) turn(dir);//越界失败
	else{
//		bool mc=mche(f,A,dir);
		bool mc=mche(f,m,dir);
			//what can i say, man,,,
		if(mc) A=m;//成功移动
		else turn(dir);//障碍失败
	}
}

bool gcha(loca &A, loca &B){//gotcha!
	return A==B;
}

int main(){
	auto [f,F,C]=scan();
	int dF=0, dC=0;//方向
	
	int roud=0;
	while(!gcha(F,C)){
		mful(f,F,dF);
		mful(f,C,dC);
		++roud;
		if(roud>10*10*4*10*10*4){//四种方向四种状态，10*10可能位置，两个对象
			//鸽巢原理
				//如果状态总数是N，根据鸽巢原理，如果模拟超过N步还没停止，
				//就一定会进入之前出现过的某个状态，从而形成环
			roud=0; break;
		}
//		cout<<F.first<<" "<<F.second<<"|"<<C.first<<" "<<C.second<<'\n';
	}
	
	cout<<roud;
}
//..........
//.....F....
//..........
//..........
//*.........
//..........
//C.........
//..........
//..........
//..........
