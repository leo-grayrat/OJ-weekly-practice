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

//哈希表的搜索更快...
//using hs=unordered_map<int,vector<int>>;//前面值，后面位置列表
using hs=map<int,vector<int>>;//哈希攻击，孩子

tuple<vi,int> get(){
	int l; //vi inp(l); 涉及大小的要注意先读再定义
	cin>>l; vi inp(l);
	for(int i=0;i<l;i++){
		cin>>inp[i].first;
		inp[i].second=false;
	}
	return {inp,l};
}

hs has(vi &inp){
	hs m; int i=0;
	for(auto &ele:inp){
		auto& tem=m[ele.first];//获取了这个值对应的位置列表；用[]保证如果尚不存在则创建
		//如果键 ele.first 不存在，它会自动创建一个空的 vector<int> 并返回其引用
		tem.push_back(i);//将这个新值的位置加入其位置列表
		++i;//索引不要忘记动！
	}
	return m;
}


int sca(vi& inp, hs& m, int i, int l){
	int add=inp[i].first+1;//之后就找比她大1的数
	int len=1;//长度
	while(1){
		//若所需数字对应的k-v对根本不存在...
		if(!m.count(add)) break;
		
		auto& lis=m[add];//这是向量
		/*
		//若最大位置仍然不在所需位置之后，则不行
		if(*max_element(lis.begin(),lis.end())<i) break;
		
		for(auto& ele:lis){
			if(ele>i){//在已给项之后的部分找
				//找到了对应的位置，更新位置和值，增加长度
				inp[i].second=true;
				i=ele;
				++add;
				++len;
				break;
			}
		}
		*/
		
		//你说得对但是
		//...upper_bound 是 C++ 标准库中的一个函数，
		//...用于在指定的范围中找到第一个大于指定值的元素...
		//而且是二分查找，很快的！
		auto fnd=upper_bound(lis.begin(),lis.end(),i); //返回是地址，减首项地址可以得到索引
		if(fnd==lis.end()) break;//找不到则返回end，注意end不指向任何元素
		else{
			int ele=*fnd;
			inp[i].second=true;
			i=ele;
			++add;
			++len;
		}
	}
	return len;
}

int cal(vi& inp, int l){
	int lon=1;
	auto m=has(inp);
	for(int i=0;i<l;i++){
		if(inp[i].second) continue; //true表示已被占用
		//剪枝，如果剩余不如现有最长的长则不管了
		if(l-i<=lon) break;
		int tem=sca(inp,m,i,l);
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
