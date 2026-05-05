#include <bits/stdc++.h>
using namespace std;
#define int long long

int tims(int i){
	if(i==1) return 1;
	int res=i*tims(i-1); return res;
}

int comb(int k, int n){
	int res=tims(n)/(tims(n-k)*tims(k));//C^n_k=n!/(n-k)!k!
	return res;
}

//先完成拆和（把大图形拆成多个小图形，如8=6+2）的部分
//不能有1边形，这就是自己给自己寄信了，最小2边形（两人互传）
using vi=vector<int>;
int counter=0;//计数器，此只在最外层运行
int each(vi& n, int a){
	
	//必要的声明
	int d=0;//delta
	int l=a;//left
	for(auto& ele:n) l-=ele;
	
	//初始化
	if(n.empty()) d=a;//d=a-2;
	//如果是空序列的开始，那么起始应该最大为总量-2
		//真的吗？别忘了他自己就是一个图形的情况
	else{	
		int t=*n.rend();//最后一个元素
		d=min(t,l);
	}
	
	//如果结果
}
