#include <bits/stdc++.h>
using namespace std;

//如果找到一条完全延伸的子序列a，那么以a上的任何元素起始的新子序列绝对不可能比a那条长
//而且如果新序列的开头不在a上，但是后续拐到了a的元素上...似乎没法确定
//但是似乎如果先找尽可能小的数开始的序列，似乎可以解决这个问题
	//但是但是这样复杂度会很高
//感觉起始位不能在以前出现的任意子序列中
	//之前是想说新子序列不能和以前任意子序列有交集，但这样不行
	//如 2 1 2 3，23比123短

using ib=pair<int,bool>;//int约-2e9~2e9，够用；bool是判断有无子序列占用过这个起始位
using vi=vector<ib>;

//感觉布尔值引入额外判断又增加复杂度了...不如搞一个单独列表用于存所有的可能起始位
/*using ii=pair<int,int>;
using vii=vector<ii>;
using vi=vector<int>;*/
//并不是，bool判断本身不会很占用，但是复杂度要考虑最坏情况，本质还tm是n^2

tuple<vi,int> get(){
	int l; //vi inp(l); 涉及大小的要注意先读再定义
	cin>>l; vi inp(l);
	for(int i=0;i<l;i++){
		cin>>inp.at(i).first;
		inp.at(i).second=false;
	}
	return {inp,l};
}

int sca(vi& inp, int i, int l){
	int add=inp.at(i).first;//之后就找比她大1的数
	int len=1;//长度
	for(i=i+1;i<l;i++){
		int tem=inp.at(i).first;
		if(tem==add+1){
			++add;
			++len;
			inp.at(i).second=true;
		}
	}
	return len;
}

int cal(vi& inp, int l){
	int lon=1;
	for(int i=0;i<l;i++){
		if(inp.at(i).second) continue; //true表示已被占用
		int tem=sca(inp,i,l);
		if(tem>lon) lon=tem;
	}
	return lon;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	auto [inp,l]=get();
	int res=cal(inp,l);
	cout<<res;
}
