#include <bits/stdc++.h>
using namespace std;
#define int long long

//错误！是202420242024个数，除的应该是10不是120
signed main(){
	int ori=202420242024;
	int cal=ori%120;
	
	int tem=0;
	int i=0, nio=1, nishi=1;
	while(i<cal){
		if(nio*20<nishi*24) ++nio;
		else ++nishi;
		++i;
		tem=min(nio*20,nishi*24);
	}
	
	int big=(ori/120)*10;
	cout<<tem+big;
}

/*signed main() {
int ori = 202420242024;

// 每 120 个数里有 10 个目标数
int cycle_count = 10;
int cycle_len = 120;

int num_cycles = ori / cycle_count; // 完整的周期数
int rem = ori % cycle_count;        // 周期后的第几个

// 找出周期内的前几个数
vector<int> sub;
for (int i = 1; i <= cycle_len; i++) {
if (i % 20 == 0 || i % 24 == 0) {
sub.push_back(i);
}
}

int ans = 0;
if (rem == 0) {
// 如果正好整除，就是上一个周期的最后一个数
ans = (num_cycles - 1) * cycle_len + sub.back();
} else {
// 周期起始值 + 周期内偏移量
ans = num_cycles * cycle_len + sub[rem - 1];
}

cout << ans << endl;
return 0;
}*/
