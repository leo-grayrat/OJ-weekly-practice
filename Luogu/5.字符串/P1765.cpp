#include <bits/stdc++.h>
//#define int long long
using namespace std;

int cou(char i){
	//离散搜索时最好构造字符串，用搜索机制去模拟匹配
	if(i==' ') 					return 1; 
	if(strchr("adgjmptw",i)) 	return 1;
	if(strchr("behknqux",i)) 	return 2;
	if(strchr("cfilorvy",i)) 	return 3;
	if(strchr("sz",i)) 			return 4;
	return 0;
}

int main(){
	string inp;
	int counter=0;
	
	getline(cin,inp);
	for(char i:inp){
		counter+=cou(i);
	}
	
	printf("%d",counter);
}
