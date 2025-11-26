#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N=5000,M=2e5;
const int inf=0x3f3f3f3f;

struct S{
    int v,d;
};

bool operator<(const S &x,const S &y){
    return x.d>y.d;
}

priority_queue<S>q;

struct node{
    int v,w,nxt;
}e[M*2];

int n,m,tot=0,cnt=0,ans=0;
int dist[N],head[N],vis[N];

void add(int u,int v,int w){
    e[tot].v=v;
    e[tot].w=w;
    e[tot].nxt=head[u];
    head[u]=tot++;
}

void Prim(){
    memset(dist,inf,sizeof(dist));
    dist[1]=0;
    for(int i=head[i];i!=-1;i=e[i].nxt){
        dist[e[i].v]=min(dist[e[i].v],e[i].w);
    }
    q.push({1,0});
    while(!q.empty()){
        if(cnt>=n) {break;}
        auto [u,d]=q.top();
        // cerr<<u<<' '<<d<<endl;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        ++cnt;
        // cerr<<u<<':'<<endl;
        ans+=d;
        for(int i=head[u];i!=-1;i=e[i].nxt){
            int v=e[i].v,w=e[i].w;
            if(w<dist[v]){
                dist[v]=w;
                q.push({v,w});
                // cerr<<v<<' '<<w<<endl;
            }
        }
    }
}

int main(){
    memset(head,-1,sizeof head);
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        // if(u==v) continue;
        add(u,v,w);
        add(v,u,w);
    }
    // cerr<<"tot:"<<tot<<endl;
    Prim();
    // cerr<<endl<<cnt<<' '<<ans<<endl;
    if(cnt==n){
        cout<<ans<<endl;
    }else{
        cout<<"orz"<<endl;
    }
    return 0;
}