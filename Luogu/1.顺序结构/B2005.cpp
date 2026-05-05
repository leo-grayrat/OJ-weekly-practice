#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,j;
	string artical;
	cin>>artical;
	//cout<<artical;

	for(i=1;i<=3;i++){
		for(j=1;j<=3-i;j++) cout<<' ';
		for(j=1;j<=2*i-1;j++) cout<<artical;
		cout<<'\n';
	}
}
