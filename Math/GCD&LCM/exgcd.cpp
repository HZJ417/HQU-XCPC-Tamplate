#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}
int main(){
    ll a,b,x,y;
    cin>>a>>b;
    exgcd(a,b,x,y);
    x=(x+b)%b;
    cout<<x<<endl;
    return 0;
}