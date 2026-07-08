#include<bits/stdc++.h>
using namespace std;

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
}

int main(){
    DSU f(n);
    int x,fx;
    cin>>x;
    fx=f.find(x);
    cout<<fx;
    int x,y;
    cin>>x>>y;
    f.Union(x,y);
    cout<<f.find(x)<<' '<<f.find(y)<<'\n';
}