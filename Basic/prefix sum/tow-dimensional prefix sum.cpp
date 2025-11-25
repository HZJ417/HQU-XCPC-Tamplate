#include<bits/stdc++.h>
#define ll long long

using namespace std;

int sum[5010][5010];

int main(){
	int n,m,ans=-2147483647;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
			int x,y,v;
			cin>>x>>y>>v;
			sum[x+1][y+1]+=v;
	}
	int N=5005;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+sum[i][j];
		}
	}
	for(int i=m;i<=N;++i){
		for(int j=m;j<=N;++j){
			int sum_tmp=sum[i][j]-sum[i-m][j]-sum[i][j-m]+sum[i-m][j-m];
			ans=max(ans,sum_tmp);
		}
	}
	cout<<ans;
	return 0;
}