#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,fir,sec,res,length;
	string status, tem_status, p1,p2,p3, ope;
	cin>>n;
	for(int i=1;i<=n;i++){
		//判断变不变运算
		cin>>tem_status;
		
		//size_t pos=0;
		//int inp=stoi(tem_status,&pos);
		//这样如果错误就会直接程序报错，无法达成捕获错误之类的目的
		//抓个第一位判断试试
		int inp=tem_status[0];
		if(inp>='a'&&inp<='c'){//如果第一个输入不是数字而是abc
			//不要忘了第一位可能是-号...
			status=tem_status;
			cin>>fir>>sec;//那么就获取后面两个数字
		}
		else{//如果第一个输入是数字，那么他就是运算式中第一项
			fir=stoi(tem_status);
			cin>>sec;//只用获取后一项
		}
		
		//根据先前确定的运算进行计算
		switch(status[0]){//此处参数需要为int或等价形式
			case 'a': res=fir+sec;ope="+";break;
			case 'b': res=fir-sec;ope="-";break;
			case 'c': res=fir*sec;ope="*";break;
		}
		
		//计算长度
		//auto [p1,p2,p3]=tuple{to_string(fir),to_string(sec),to_string(res)};
		//结构化绑定只能用于声明新变量
		p1 = to_string(fir);p2 = to_string(sec);p3 = to_string(res);
		length=p1.length()+p2.length()+p3.length()+2;
		//集体输出
		cout<<p1<<ope<<p2<<"="<<p3<<endl;
		cout<<length<<endl;
	}
}
