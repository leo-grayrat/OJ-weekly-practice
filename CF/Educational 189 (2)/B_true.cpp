#include <bits/stdc++.h>
using namespace std;
#define int long long
using v=vector<char>;
/*大变申*/
/*第二部和第三步选的字符串得是一样的*/
/*下文事按照选的子字符串可以不一样去写的*/
/*先提交了再说罢*/
/*草泥马能不能好好读题*/
	/*更大变申*/
	/*只要交替就可以，没人叫你ababababab啊啊啊啊啊啊*/
bool pre(string& inp){
//	int cou=0;//tft变换次数
	v che;//切换时各位位置
	bool bef=true;//true表示为正常
//	for(int i=0; i<inp.length(); ++i){
//		char t = i%2?'b':'a';
//		bool now = inp[i]==t;
	for(int i=1; i<inp.length(); ++i){
		char t;
		if(inp[0]=='a') t = i%2?'b':'a';
		else t = i%2?'a':'b';
		//丑陋的补丁……实际上应该有个子逻辑判断符不符合的
		
		bool now = inp[i]==t;
		if(now!=bef) {//可能: T-F(进入), F-T(可能), T-F(多余)
			//正常的是0~4次, 记录的是第1次之后第4次之前的长度
			che.push_back(i);//新的一次变换
			if(che.size()>2) return false;//超过4次
			bef=now;
		}
	}
//	if(che.size()<2) /*顶多只有一次F*/ return true;
//	else if(che.size()==2) che.push_back(inp.length());//缺一次的话就是F一直到结尾
//	//最后合算第1次之后第4次之前的长度, 也就是che3-che0, 应该为奇数
//	int fin=che[1]-che[0];
//	return fin%2==1;
	return true;
}

//只能最多FTF，不能再多F了，FTF之和必须为奇数
	//发现读错题之后，实际上问题本身简单得多
		//1.只有一段F：奇数则换+翻，偶数则翻
		//2.FTF，对这一整段换，变成TFT，之后取决于F（原T）
			//如果偶数则翻可以，奇数则失败……
		//并不是，FTF根本不可以
//若为F则无论如何有办法处理
signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin>>n;
	v a(n);
	for(int i=0; i<n; ++i){
		string inp; cin>>inp;
		string res = pre(inp)?"YES":"NO";
		cout<<res<<'\n';
	}
	
}
