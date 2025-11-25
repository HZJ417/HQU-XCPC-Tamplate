#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=150000;
const int M=550000;
struct node{
	int v,w,nxt;
}edge[M];
int head[N],vis[N],tot=0;
ll dist[N];
typedef pair<int,int> PII;
priority_queue<PII, vector<PII>, greater <PII> > q;
inline void add(int u,int v,int w){
	edge[tot].v=v;
	edge[tot].w=w;
	edge[tot].nxt=head[u];
	head[u]=tot++;
}
inline void dijkstra(int x){
	memset(dist,0x3f,sizeof(dist));
	dist[x]=0;
	q.push(make_pair(0,x));
	while(!q.empty()){
		PII tmp=q.top();
		q.pop();
		int v=tmp.second;
		int d=tmp.first;
		if(vis[v]) continue;
		vis[v]=1;
		for(int j=head[v];j!=-1;j=edge[j].nxt){
			int u=edge[j].v;
			if(dist[u]>d+edge[j].w) dist[u]=d+edge[j].w;
			q.push(make_pair(dist[u],u));
		}
	}
}
int main(){
	memset(head,-1,sizeof(head));
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	dijkstra(s);
	for(int i=1;i<=n;++i){
		if(dist[i]>2147483647) cout<<"2147483647 ";
		else cout<<dist[i]<<" ";
	}
	return 0;
}
