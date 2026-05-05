#include <bits/stdc++.h>
using namespace std;

int& pas(char inp, int& a, int& b, int& c){
	if(inp=='a') 		{int& lef=a;return lef;}
	else if(inp=='b') 	{int& lef=b;return lef;}
	else 	{int& lef=c;return lef;}
	//实际上可以直接return a/b/c
}

int main(){
	int a=0,b=0,c=0;
	
	string pri="0",sen="0";
	while(pri!=""&&sen!=""){
		getline(cin,pri,':');
		cin.ignore(1);
		getline(cin,sen,';');
		if(cin.fail()) break;
		/*
		switch(pri.at(0)){
			case 'a': {int& lef=a; break;}
			case 'b': {int& lef=b; break;}
			case 'c': {int& lef=c; break;}
		}
		*/
		//switchcase内部定义的只是局部变量
		int& lef=pas(pri.at(0),a,b,c);
		if(isdigit(sen.at(0))){
			//右值是数字
			lef=stoi(sen);
		}
		else{
			//右值是变量
			int& rig=pas(sen.at(0),a,b,c);
			lef=rig;
		}
	}
	
	cout<<a<<" "<<b<<" "<<c;
}
