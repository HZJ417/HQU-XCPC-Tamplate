#include<bits/stdc++.h>
using namespace std;
const int N=30010;
const int M=60010;
struct node{
    int u,v,w;
}g[M];
struct edge{
    int u,v,nxt;
}G[M];
int n,m,k,p,tot=0,cnt=0;
int head[N],val[N];
int f[N],dfn[N],tim[N],id[N],dep[N],st[N][20];
struct DSU{
    vector<int>f;
    DSU(int n){
        f.resize(n+1,0);
        for(int i=1;i<=n;++i) f[i]=i;
    }
    int find(int x){
        return x==f[x] ? x : f[x]=find(f[x]);
    }
    bool Union(int x,int y){
        x=find(x),y=find(y);
        if(x==y) return false;
        f[x]=y;
        return true;
    }
};
void add(int u,int v){
    G[++tot].u=u;
    G[tot].v=v;
    G[tot].nxt=head[u];
    head[u]=tot;
}
bool cmp(node a,node b){
    return a.w<b.w;
}
void exKruskal(){   
    DSU fa(N);
    sort(g+1,g+1+m,cmp);
    for(int i=1;i<=m;++i){
        int x=g[i].u,y=g[i].v;
        x=fa.find(x),y=fa.find(y);
        if(x!=y){
            val[++p]=g[i].w;
            fa.f[p]=p,fa.f[x]=p,fa.f[y]=p;
            // cout<<x<<' '<<p<<'/'<<y<<' '<<p<<endl;
            add(p,x);add(x,p);
            add(p,y);add(y,p);
        }
    }
}
void dfs(int u,int fa){
    // cout<<u<<':'<<endl;
    f[u]=fa;
    dfn[u]=++cnt;
    id[cnt]=u;
    dep[u]=dep[fa]+1;
    for(int i=head[u];i;i=G[i].nxt){
        int v=G[i].v;
        // cout<<u<<' '<<v<<endl;
        if(v==fa) continue;
        dfs(v,u);
    }
    tim[u]=cnt;
}
int update(int x,int y){
    if(dep[x]<dep[y]) return x;
    return y;
}
void rmq(int n){
    for(int i=1;i<=n;++i){
        st[i][0]=id[i];
    }
    for(int j=1;j<=(__lg(n));++j){
        for(int i=1;i+(1<<j)-1<=n;++i){
            st[i][j]=update(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}
int LCA(int x,int y){
    if(dfn[x]>dfn[y]) swap(x,y);
    // if(dfn[x]<=dfn[y]&&tim[x]>=tim[y]) return x;
    x=dfn[x],y=dfn[y];
    int k=__lg(y-x+1);
    return f[update(st[x][k],st[y-(1<<k)+1][k])];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        g[i]={u,v,w};
        
    }
    p=n;
    exKruskal();
    dfs(p,0);
    // for(int i=p;i>=1;--i){
    //     if(!dfn[i]){
    //         dfs(i,0);
    //     }
    // }
    rmq(p);
    // cout<<p<<endl;
    while(k--){
        int u,v;
        cin>>u>>v;
        cout<<val[LCA(u,v)]<<'\n';
    }
    return 0;
}