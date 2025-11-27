#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int N=5e4+100;
int dfn[N],low[N],cnt=0,s[N],vis[N],top=0;
int scc[N],sc;
int siz[N];

struct node{
    int v,nxt;
}edge[N];

int head[N],tot=0;

void add(int u,int v){
    edge[i].v=v;
    edge[i].nxt=head[u];
    head[u]=++tot;
}

void tarjan(int u){
    low[u]=dfn[u]=++cnt;
    s[++top]=u,vis[u]=1;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].v;
        if(!dfn[v]){
            tarjan(v);
            low=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        ++sc;
        do{
            scc[s[top]]=sc;
            siz[sc]++;
            vis[s[top]]=0;
        }while(s[top--]!=u);
    }
}

int main(){

    return 0;
}