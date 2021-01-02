#include <bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
#define re register
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(re int i=a;i<=b;++i)
#define per(i,a,b) for(re int i=a;i>=b;--i)
template<typename T>
inline void read(T&x)
{
	x=0;
	char s=(char)getchar();
	bool f=false;
	while(!(s>='0'&&s<='9'))
	{
		if(s=='-')
			f=true;
		s=(char)getchar();
	}
	while(s>='0'&&s<='9')
	{
		x=(x<<1)+(x<<3)+s-'0';
		s=(char)getchar();
	}
	if(f)
		x=(~x)+1;
}
template<typename T,typename ...T1>
inline void read(T&x,T1&...x1)
{
	read(x);
	read(x1...);
}
template<typename T>
inline void clear(T*array,int l,int r,int val)
{
	memset(&array[l],val,sizeof(T)*(r-l+1));
}
using namespace std;
const int N=1e5+5;
int n,q;
int head[N],num_edge;
struct Edge
{
	int next,to,dis;
} edge[N<<1];
inline void add_edge(int from,int to,int dis)
{
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	edge[num_edge].dis=dis;
	head[from]=num_edge;
}
ll dep1[N],dep2[N];
inline void dfs(int u,int fa,ll *dep)
{
	for(int i=head[u]; i; i=edge[i].next)
	{
		int &v=edge[i].to;
		if(v==fa)
			continue;
		dep[v]=dep[u]+edge[i].dis;
		dfs(v,u,dep);
	}
}
signed main()
{
//	freopen("distance.in","r",stdin),freopen("distance.out","w",stdout);
	read(n,q);
	for(int i=1; i<n; ++i)
	{
		int u,v,w;
		read(u,v,w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	for(int q1=1; q1<=q; ++q1)
	{
		int u,v;
		read(u,v);
		memset(dep1,0,sizeof(dep1));
		memset(dep2,0,sizeof(dep2));
		dfs(u,0,dep1);
		dfs(v,0,dep2);
		ll maxx=0;
		for(int i=1; i<=n; ++i)
			maxx=max(maxx,min(dep1[i],dep2[i]));
		printf("%lld\n",maxx);
	}
	return 0;
}


