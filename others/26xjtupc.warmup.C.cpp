#include <bits/stdc++.h>
using namespace std;
#define int long long

using ij=pair<double,double>;
using v=vector<double>;

/*
思考点一：如果不考虑消除呢？
假设我们修改一下规则：杯子容量无限大，两个 H 碰在一起不会流光，
而是可以各自独立地继续往右倒，直到全部掉出最右边。
在这种“绝对不发生消除”的平行宇宙里，你觉得这个游戏总共会进行多少步？
这时的胜负由什么决定？
思考点二：消除到底“消掉”了什么？（最关键的一步）
现在回到真实的游戏规则。就像你在样例一中分析的，
某个 H 往右倒，撞上了另一个 H，两个 H 一起“嘭”地消失了。
请你仔细想一想，在这个“发生碰撞并双双消失”的瞬间：
原本在左边主动倒过来的那个 H，它还剩下多少“距离”没有走？
原本停留在右边被砸中的那个 H，它还剩下多少“距离”没有走？
这两个数字之间有什么关系？它们两个的消失，导致游戏总共减少了多少步？
这个减少的步数，是奇数还是偶数？
*/
signed main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	string all; cin>>all; bool win=false;
	for(auto it=all.rbegin(); it!=all.rend(); ++it){
		int dis=it-all.rbegin()+1;
		if(*it=='E'||*it=='F') continue;
		if(dis%2) win=!win;
	}
	if(win) cout<<"Alice";
	else cout<<"Bob";
}
