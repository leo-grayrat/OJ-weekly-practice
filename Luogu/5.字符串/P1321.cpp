#include <bits/stdc++.h>
//#define int long long
using namespace std;

//事后诸葛亮：担心可能“匹配的有可能1/2/3/4个字母，情况复杂”并非！**或**不就行了，管你匹配到底几个

using bg=pair<int,int>;

bg yaoiyuri(string& inp){
	unsigned long long pos;
	
	auto clb={"boy","bo!","!oy","!!y","b!!","!o!"},//checklistboy/girl
	clg={"girl","gir!","!irl","gi!!","!!rl","g!!!","!i!!","!!r!","!!!l"};
	//通配符，感叹号即逆向后的未知字符
	bg ori{-1,-1},tem{0,0};
	//如何避免死循环？每过一个循环更新一次bg数，如果没变化那就寄了
	
	while(ori!=tem){
		ori=tem;//更新循环
		
		int boy=0,girl=0;//以上两个都是循环内部临时变量
		for(auto otoko:clb){			
			pos=inp.find(otoko);
			if(pos==string::npos) continue;
			else {
				boy++;
				//找到了就要替换！
				inp.replace(pos,3,"!!!");
				//cout<<inp<<"|test  boy|"<<'\n';
			}
		}
		for(auto onanoko:clg){			
			pos=inp.find(onanoko);
			if(pos==string::npos) continue;
			else {
				girl++;
				//找到了就要替换！
				inp.replace(pos,4,"!!!!");
				//cout<<inp<<"|test girl|"<<'\n';
			}
		}
		
		tem=make_pair(tem.first+boy,tem.second+girl);//不能直接加
		//你直接检测是否boygirl全为0不就行了？不过这样输出值不好
	}
	
	return ori;
}

int main(){
	string inp;
	cin>>inp;
	
	bg res=yaoiyuri(inp);
	cout<<res.first<<'\n'<<res.second;
}
