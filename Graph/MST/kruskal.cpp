#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,m,i,j,u,v,total;
struct edge {
	int start,to;
	long long val;
} bian[2000005];
int f[100000];
long long ans;
int find(int x) {
	if (f[x]==x) return x;
	else {
		f[x]=find(f[x]);
		return f[x];
	}
}
bool cmp(edge a,edge b) {
	return a.val<b.val;
}
inline void kruskal() {
	for(int i=1; i<=m; i++) {
		u=find(bian[i].start);
		v=find(bian[i].to);
		if(u==v) continue;
		ans+=bian[i].val;
		f[u]=v;
		total++;
		if(total==n-1) break;
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(i=1; i<=n; i++) f[i]=i;
	for(i=1; i<=m; i++) {
		scanf("%d%d%d",&bian[i].start,&bian[i].to,&bian[i].val);
	}
	sort(bian+1,bian+m+1,cmp);
	kruskal();
	if(total==n-1) printf("%d",ans);
	else printf("orz");
	return 0;
}