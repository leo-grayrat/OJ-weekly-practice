#include <bits/stdc++.h>
using namespace std;
//#define _GLIBCXX_DEBUG

using ap=deque<pair<int,int>>;
deque<char> add(ap& inp){
	deque<char> res; bool car=false;
	for(auto it=inp.end()-1; it>=inp.begin(); --it){
		auto ele=*it;
		int sum=ele.first+ele.second+car;//进位
		
		//多么优雅
		car = sum<10 ? false : true;
		res.push_front('0' + sum % 10);
		
//		if(sum<10) {
//			res.push_front('0'+sum);
//			car=false;//不进位
//		}
//		else{
//			sum-=10;
//			res.push_front('0'+sum);
//			car=true;//要进位
//		}
	}
	//但是,如果最后一位有进位,现在这样是识别不了的,因为迭代器搜完了循环退出了
	if(car) res.push_front('1');
	return res;
}

int main(){
	string a,b;
	cin>>a>>b;
	
	int len=max(a.length(),b.length());//最大数的位数
	int dif=len-min(a.length(),b.length());//为了方便计算之后要补齐小的数的前导零
	string& sho=a.length()<b.length()?a:b;
	for(int i=1; i<=dif; ++i) sho="0"+sho;//补全
	
	ap inp;
	for(int i=len-1; i>=0; i--){
		int A=a.at(i)-'0',B=b.at(i)-'0';//右边是char类型
		auto p = make_pair(A,B);
		inp.push_front(p);
	}
	
	auto res=add(inp);
	for(auto &ele:res){ 
		
		cout<<ele;
	}
}
// 都用deque比较好,干嘛计较索引呢,这样很容易出错
