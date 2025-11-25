#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(j);i<=(k);++i)
#define dep(i,j,k) for(int i=(j);i>=(k);--i)
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N=4e3+100;
const int inf=1e9;
struct node{
    int v,w,nxt;
}edge[N*4];
int tot=0,head[N],vis[N],t[N];
int h[N],dis[N];
int n,m;
void add(int u,int v,int w){
    edge[++tot].v=v;
    edge[tot].w=w;
    edge[tot].nxt=head[u];
    head[u]=tot;
}
bool spfa(int s){
    queue<int> q;
    memset(h,0x3f3f3f3f,sizeof h);
    h[s]=0,vis[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].v;
            if(h[v]>h[u]+edge[i].w){
                h[v]=h[u]+edge[i].w;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                    t[v]++;
                    if(t[v]==n+1) return false;
                }
            }
        }
    }
    return true;
}
void dij(int s){
    priority_queue<pii,vector<pii>,greater<pii> >q;
    rep(i,1,n) dis[i]=inf;
    memset(vis,0,sizeof vis);
    dis[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty()){
        pii tmp=q.top();
        q.pop();
        int u=tmp.second,d=tmp.first;
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].v;
            if(dis[v]>dis[u]+edge[i].w){
                dis[v]=dis[u]+edge[i].w;
                q.push(make_pair(dis[v],v));
            }
        }
    } 
}
void solve(){
    cin>>n>>m;
    rep(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    rep(i,1,n){
        add(0,i,0);
    }
    if(!spfa(0)){
        cout<<"-1"<<endl;
        return;
    }
    // rep(i,1,n){
    //     cerr<<h[i]<<' ';
    // }
    // cerr<<'\n';
    rep(u,1,n){
        for(int j=head[u];j;j=edge[j].nxt){
            edge[j].w+=h[u]-h[edge[j].v];
        }
    }
    rep(i,1,n){
        dij(i);
        int ans=0;
        rep(j,1,n){
            if(dis[j]==inf) ans+=j*inf;
            else ans+=j*(dis[j]+h[j]-h[i]);
        }
        cout<<ans<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}