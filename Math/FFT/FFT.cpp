#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
struct Complex{
    double a,b;
    Complex(double x=0,double y=0){a=x,b=y;}
}x[N],y[N];
const double Pi=acos(-1.0);
Complex operator + (const Complex& x,const Complex& y){return Complex(x.a+y.a,x.b+y.b);}
Complex operator - (const Complex& x,const Complex& y){return Complex(x.a-y.a,x.b-y.b);}
Complex operator * (const Complex& x,const Complex& y){return Complex(x.a*y.a-x.b*y.b,x.a*y.b+x.b*y.a);}
int n,m;
int l,r[N];
int len=1;
void FFT(Complex *A,int type){
    for(int i=0;i<len;++i){
        if(i<r[i]) swap(A[i],A[r[i]]);
    }
    for(int mid=1;mid<len;mid<<=1){
        Complex Wn( cos(Pi/mid) , type*sin(Pi/mid) );
        for(int R=mid<<1,j=0;j<len;j+=R){
            Complex w(1,0);
            for(int k=0;k<mid;++k,w=w*Wn){
                Complex x=A[j+k],y=w*A[j+mid+k];
                A[j+k]=x+y;
                A[j+mid+k]=x-y;
            }
        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<=n;++i) cin>>x[i].a;
    for(int i=0;i<=m;++i) cin>>y[i].a;
    while(len<=n+m) len<<=1,l++;
    for(int i=0;i<len;++i) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
    FFT(x,1);
    FFT(y,1);
    for(int i=0;i<len;++i) x[i]=x[i]*y[i];
    FFT(x,-1);
    for(int i=0;i<=n+m;++i) cout<<(int)(x[i].a/len+0.5)<<' ';
    return 0;
}