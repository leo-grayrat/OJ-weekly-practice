#include <bits/stdc++.h>
using namespace std;
//P1598

using vi=vector<int>;
vi coun(){
	vi alp(26,0);
	
	string all="";
	for(int i=1;i<=4;i++){
		string line="";
		getline(cin,line);
		all+=line;
	}
	
	for(auto let:all){
		if(let>='A'&&let<='Z'){
			int diff=let-'A';//偏移量
			++alp.at(diff);
		}
	}
	
	return alp;
}

void draw(vi cou){
	int maxl=*max_element(cou.begin(),cou.end());
	for(int i=maxl;i>=1;--i){
		string thisline="";
		for(auto ele:cou){
			//举例：第1行i=maxl，此时其他列ele<maxl=i，不够
			char out=ele<i?' ':'*';
			//cout<<out<<" ";//不要忘了样例输出中有空格
			thisline=thisline+out+' ';//见45行左右
		}
		//行末多余空格怎么办？之前就别直接输出了，先暂存一下到string里
		thisline.pop_back();//pop_back() 用于删除字符串末尾的字符
		//输出，并行末换行
		cout<<thisline<<'\n';
	}
	//最后还有标签行
	string tab="";
	for(char alp='A';alp<='Z';++alp){
		//tab+=(alp+" ");
		//+=时，编译器看到第一项是内置类型（此处的char），就会触发算术加法而不是拼接
		//在 += 后面尽量不要给复杂的运算加括号！！！
		tab=tab+alp+" ";//加号（+）的其中一边是 std::string 对象
	}
	tab.pop_back();
	cout<<tab;
}

int main(){
	draw(coun());
}
