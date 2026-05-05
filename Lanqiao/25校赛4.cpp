#include <bits/stdc++.h>
using namespace std;

void prt(int tim){
	for(int i=0; i<tim; ++i){
		cout<<"Q";
	}
}
void each(int w, int h){
	for(int i=0; i<h; ++i){
		prt(w);
		if(i!=h-1) cout<<'\n';
	}
}

int main(){
	int w,h,v; cin>>w>>h>>v;
	each(w,h); 
		cout<<'\n';
	each(w+v,w);
}
