#include <bits/stdc++.h>
using namespace std;

void prt(int pos){
	int i=pos%4;
	if(i==0||i==2) cout<<"2";
	if(i==1) cout<<"0";
	if(i==3) cout<<"5";
}
void each(int sta, int w){
	for(int i=0; i<w; ++i){
		prt(sta); ++sta;
	}
	
}

int main(){
	int h,w; cin>>h>>w;
	for(int i=0; i<h; ++i){
		each(i,w);
		if(i!=h-1) cout<<'\n';
	}
}
