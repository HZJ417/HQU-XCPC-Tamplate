#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(j);i<=(k);++i)
#define dep(i,j,k) for(int i=(j);i>=(k);--i)
using namespace std;
const int inf=0x3f3f3f3f;
int mp[110][110];
void solve(){
	memset(mp,inf,sizeof mp);
	int n,m;
	cin>>n>>m;
	rep(i,1,n){
		mp[i][i]=0;
	}
	rep(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=w;
		mp[v][u]=w;
	}
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				if(mp[i][j]>mp[i][k]+mp[k][j]){
					mp[i][j]=mp[i][k]+mp[k][j];
				}
			}
		}
	}
	rep(i,1,n){
		rep(j,1,n){
			cout<<mp[i][j]<<' ';
		}
		cout<<'\n';
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