#include <bits/stdc++.h>
using namespace std;


int main(){
	int man,dri;
	cin>>man>>dri;
	vector<bool> chosen(dri,true);
	
	for(int i=0;i<man;i++){
		int cup; cin>>cup;//换行符！
		string inp; getline(cin,inp);getline(cin,inp);
		stringstream line(inp);
		for(int j=0;j<cup;j++){
			int cho; line>>cho;
			if(chosen.at(cho-1)) {
				cout<<cho<<'\n';
				chosen.at(cho-1)=false;
				break;
			}
			if(j==cup-1 )cout<<"0\n";
		}
	}
}
