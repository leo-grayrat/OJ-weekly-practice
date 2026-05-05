#include <bits/stdc++.h>
using namespace std;

//表面上是个线代问题，实际上不尽然
//因为每种移动只能做自然数次，负数和非整数都不行
//可以解得 a=c+y+1;b=1/3*(x-2*y)-2*c;c=c
//显然a显然为正整数，那么关键就是b
//而c是自由变量，所以无所谓，最坏情况取0即可
//则只用看x-2y能否被3整除，且为正

int main(){
	int N; cin>>N;
	for(int i=0; i<N; i++){
		int x,y; cin>>x>>y;
		if((x-2*y)%3!=0) 	cout<<"NO"<<'\n';
		else if((x-2*y)<0)	cout<<"NO"<<'\n';
		else				cout<<"YES"<<'\n';
	}
}
