#include <bits/stdc++.h>
using namespace std;
//#define _GLIBCXX_DEBUG

//你要不要脸？
class name{
public:
	int b; int c;
	void clear(){
		b=1; c=0;
	}
};

void pri(name& inp, string& a){
	auto b=inp.b; auto c=inp.c;
	cout<<a;
	if(b!=1) cout<<" ("<<b<<")";
	for(int i=0; i<c; ++i){
		cout<<" - Copy";
	}
}

int main(){
    string a="New Folder";
    vector<name> all(3);
	for(auto& ele : all) ele.clear();
	
	//第一步只能是1
	{
		int inp; cin>>inp;
		if(inp==1) {
			pri(all[0],a);
		}
		cout<<'\n'	;
	}
	
    for(int i=1;i<=2;++i){
        int inp; cin>>inp;
        if(inp==1){
            all[i]=all[i-1];
			all[i].b++;
			all[i].c=0;
			pri(all[i],a);
        }
        if(inp==2){
			bool spe=false;
            int which; cin>>which;
            all[i]=all[which-1];
			all[i].c++;
			for(int j=0; j<i; ++j){
				if(all[i].b==all[j].b
				   &&all[i].c==all[j].c){ 
					if(all[i].b!=1)	all[i].b++;
					else spe=true;
				}
			}
			pri(all[i],a);
	        if(spe)	cout<<" (2)";
		}
		cout<<'\n'	;
    }
}
