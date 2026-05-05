#include <bits/stdc++.h>
using namespace std;

//递归绝对死得很惨，要想通过得调用之前的值...
//但是更大的问题是50!超过了ll的数量级...
using nu=deque<int>;
auto mul(nu& bef, nu& now){
	//bef是上一步的结果，now是这一步要乘的
	int coub=0, leng=bef.size()+now.size();//99*99<100*100=1e4五位数=>最多a+b位
	nu res(leng);//这次不map了
	for(auto ib=bef.rbegin(); ib!=bef.rend(); ++ib){
		int coun=0;
		for(auto in=now.rbegin(); in!=now.rend(); ++in){
			res.at(coub+coun)+=(*ib)*(*in);
			++coun;
		}
		++coub;
	}
	//进位
	int car=0;
	for(auto& ele:res){
		ele+=car;
		car=ele/10;
		ele=ele%10;
	}
	//此时数字是反的，需要有反转
	reverse(res.begin(),res.end());
	//去除前导零，如有
	for(auto& ele:res){
		if(ele==0) res.pop_front();
		else break;
	}
	//输出
	return res;
}

//想一想觉得当初乘法用2*deque 加法用vector<pair>确实是明智的，加法需要对齐位数而乘法不用
auto add(nu& bef, nu& now){
	int bs=bef.size(), ns=now.size();
	nu& sma=bs>ns?now:bef;
//	//分为两段，前面是正常加，后面等到有一个的位数耗尽之后变成长的那个+进位
//	nu res(bs+1);//实际上这里push_front也行，但是也试试索引写法
//	//需要把befnow反向，否则怎么对齐
//	reverse(bef.begin,now)
//	for(int i=0; i<bs; ++i){
//		int bt=
//	}
	//以上的想法还是太麻烦了，补齐就没有那么多问题了
	int dif=abs(bs-ns);
	for(int i=0; i<dif; ++i){
		sma.push_front(0);
	}
	nu res; int car=0;
	for(int i=bs-1; i>=0; --i){//反向
		int bt=bef.at(i), nt=now.at(i);
		int tem=bt+nt+car;
		car=tem/10;
		tem=tem%10;
		res.push_front(tem);//输出结果是正向的，符合普通数字
	}
	if(car) res.push_front(car);//只可能进位一次
	
	return res;
}

auto tra(int i){
	nu out;
	while(i){
		out.push_front(i%10);
		i/=10;
	}
	return out;
}

auto pro(int n){
	nu sum(1,0), cro(1,1);
	//sum是上一步加和的结果，cro是上一步阶乘的结果
	for(int i=1; i<=n; ++i){
		nu t=tra(i);//要乘的数
		//这一步阶乘结果
		cro=mul(cro,t);
		//这一步总加和结果
		sum=add(cro,sum);
	}
	return sum;
}

void pri(nu& res){
	//数据是按顺序排列的，所以直接打印即可
	for(auto &ele:res) printf("%d",ele);
}

int main(){
	int n;
	scanf("%d",&n);
	auto res=pro(n);
	pri(res);
}
