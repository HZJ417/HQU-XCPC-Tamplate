#include<bit/stdc++.h>
using namespace std;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<' '<<lcm(a,b);
    return 0;
}