#include <bits/stdc++.h>
using namespace std;

using dp=pair<double,double>;
using dpp=vector<dp>;
double dis(dp a,dp b){
	double res=sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
	return res;//用hypot直接算
}

double tri(dp a,dp b,dp c){
	double res=dis(a,b)+dis(a,c)+dis(b,c);
	return res;
}

int main(){
	/*dpp inp(3);
	for(auto ele:inp){
	cin>>ele.first>>ele.second;
}
	double res=tri(inp.at(0),inp.at(1),inp.at(2));*/
	//别随便用vector比较好？
	//因为你没有加引用...
	
	dp a,b,c;
	cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
	double res=tri(a,b,c);
	printf("%.2lf",res);
}
