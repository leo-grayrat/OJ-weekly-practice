#include <bits/stdc++.h>
using namespace std;
//#define _GLIBCXX_DEBUG
#define int long long

using di=deque<int>;
di add(di& a, di& b){
	map<int,int> res; int acou=0;
	for(auto it=a.rbegin(); it!=a.rend(); ++it){//反向迭代器孩子！
		auto aele=*it; //int acou=0;//表示这是第几位,从0开始
			//我劝你好好想一想定义循环变量应该在哪里定义在哪里初始化！！！
			//在开始循环前！！！
		
		int bcou=0;
			//我劝你好好想一想定义循环变量应该在哪里定义在哪里初始化！！！
			//在开始循环前！！！
		for(auto jt=b.rbegin(); jt!=b.rend(); ++jt){
			auto bele=*jt; //int bcou=0;
			
			//最好先算再进位，否则中间过程太多
			//此时发现只能逆向存数字了，否则索引怎么办
			//而且不定的范围导致我们不能用vectordeque这样的，只能map
				//关联式容器的operator[]会自动帮用户扩容
			
			res[acou+bcou]+=aele*bele;//若不存在，则自动创建并初始化为0，之后再+=
			
			++bcou;//不要忘记自加这种附加计数变量
		}
		++acou;
	}
	
	//计算结束后这个图的key一定从0开始且连续
	int s=res.size(); // 0~s-1
	
	//算完之后开始进位
	int car=0;//进位用
	
	di mul;//输出结果仍然用deque，方便pushfront，不用后面再反转了
	for(int i=0;i<s;i++){
		int tem=res[i]+car;
		car=tem/10;//进位数
		mul.push_front(tem%10);
	}
	
	//最后一位有进位
	while(car){ //多次进位！！！
		mul.push_front(car%10);
		car=car/10;
	}
	
	while(*mul.begin()==0) mul.pop_front();//前导零去除机制,也为了处理0*x
//	for(auto& ele:res) cout<<ele.first<<" "<<ele.second<<"|";
//	cout<<"\n";
	
	return mul;
}

signed main(){
	string a,b;
	cin>>a>>b;
//	stringstream as(a), bs(b);
//	
	di ad,bd; //int tem;
//	while(as>>tem) ad.push_back(tem);
//	while(bs>>tem) bd.push_back(tem);
	//需要一位一位读，ss没得用
	//而且此时顺序读取会从前往后读，所以应该push_front
		//真的是这样吗？？？
	for(auto& ele:a) ad.push_back(ele-'0');
	for(auto& ele:b) bd.push_back(ele-'0');
	
	if(a=="0"||b=="0") cout<<"0";//如果是0...会有很多个0
		//其实如果要加前导零去除机制的话和那个合并比较好...
	else {
		auto res=add(ad,bd);
		for(auto &ele:res) cout<<ele;
	}
}
// 都用deque比较好,干嘛计较索引呢,这样很容易出错

