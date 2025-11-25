#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve(){
	string s;
	getline(cin,s);
	istringstream iss(s);//devide by ' '
	string op;
	while(iss>>op){
		istringstream iss_(op);
		string _s;
		while(getline(iss_,_s,',')){//devide by ','
			cout<<_s<<endl;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}