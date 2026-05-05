#include <bits/stdc++.h>
using namespace std;

using vi=vector<int>;
//using mt=pair<int,int>;//Machine&Time
using mp=vector<int>;//ManyParts
using vp=vector<mp>;
auto sca(){
	int m,n; cin>>m>>n;
	vi ord(m*n);//只有 工序数（机器数）*工件数 个工序
	for(auto& ele:ord) {
		cin>>ele;
		//为保证全局都是0索引，此处录入值自刎归天（划掉）自减1
		--ele;
	}
	
	vp mac(n), tim(n);
	for(int i=0; i<n; ++i){
		mp eac(m);
		for(int j=0; j<m; ++j){
			int& tem=eac.at(j);
			cin>>tem;
		}
		mac.at(i)=eac;
	}
	for(int i=0; i<n; ++i){
		mp eac(m);
		for(int j=0; j<m; ++j){
			int& tem=eac.at(j);
			cin>>tem;
		}
		tim.at(i)=eac;
	}
	//因为如果仍然把machine和time捆绑，则最后合并到vp时不好处理，会互相覆盖
	return make_tuple(m,n,ord,mac,tim);
}

struct sta{
	int item; int proc; int timl;
	//工件？工序？剩余时间？
};
using pa=vector<pair<int,bool>>;//（做到第几个工序了+true/false在做）

bool ful(pa& whi, int& m){
	//检测有无完成
	for(auto& ele:whi){
		if(ele.first!=m) return false;//进行到最后一个工序
		if(ele.second) return false;//而且已经做完了
	}
	return true;
}
//检测完成还是用输入队列读取完毕的判断吧
	//不可以！一方面是机器状态，一方面是工件状态，两个都不能丢

auto pro(int& m, int& n, vi& ord, vp& mac, vp& tim){
	mp whi(n,1);//我们先要知道每个部件做到第几个工序了
	int cou=0;
	
//大変申！题中是步骤安排顺序（就像先后去挑选时间）不是事实上进行的顺序（挑选的时间的先后）
	tuple<vector<sta>,pa> eth;//everything u need;
//I HATE THIS PROBLEM!
	
	//理论上说要想最小化信息量应该把工件-机器对应起来，但是...工程量有点大
	//所以我们单独记录工件和机器信息，不互相耦合/调用，虽然会有相互间重复部分但更一目了然
	vector<sta> allm(m);//所有机器现状的必要信息
	pa allp(n,{0,false});//所有工件的信息（做到第几个工序了+在不在做）
	auto it=ord.begin();//在此时刻之后进行哪一步，默认在第一位处
	while(ful(allp,m)){
		//第一：所有工件的工作又进行了一单位时间，更新机器中的剩余时间
		for(auto& ele:allm){
			--ele.timl;//如果有机器闲置若干回合，此数值会是负的
			//第二，如果有工序的工作刚刚结束，更新工件状态至工作完毕
			if(ele.timl==0){
				int i=ele.item, p=ele.proc;
				//将信息传到工件状态
				allp[i].second=false;
				//此时不要变工序数！等到新工序开始时再变
			}
		}
		//第三，尝试进行下一步工作，即检查下一步对应的工件和机器是否空闲
		int now=*it;
		bool mfre=allp.at(now).second;//machine free
		if(!mfre){//说明是false，前面工序已经没在工作了
			//确定该第几个工序了
			int ste=allp.at(now).first;
			//找到now工件ste工序对应哪个机器，通过mac数据
			int wmac=mac.at(now).at(ste);
			//检查wmac号机器现在在不在工作，即看timl有没有耗尽
			int timl=allm.at(wmac).timl;
			if(timl<=0){
				//第四，确定机器和工件都空闲之后，开始工作，更新两方信息
				int ntim=tim.at(wmac).at(now);//tim找到耗时数据
				//wmac号机器 now工件 ste工序 ntim耗时
				//机器方需要 工件 工序 剩余时间
				allm.at(wmac).item=now;
				allm.at(wmac).proc=ste;
				allm.at(wmac).timl=ntim;
					//allm.at(wmac){now,ste,ntim};这特么是初始化不是赋值，别乱用
				//工件方需要 工序 是否正在工作
				++allp.at(now).first;//现在可以推进到下一个工序了
					//此处最多增到m-1,不用担心越界
					//因为触发这些需要输入的顺序里面出现对应的工件，而其出现次数是有限的
				allp.at(now).second=true;//正在工作
				//第五（最后），记得这一步进成功之后it要后移，下一次探测下一个步骤
				++it;
			}
		}
		
		++cou;//勿忘
	}
}
