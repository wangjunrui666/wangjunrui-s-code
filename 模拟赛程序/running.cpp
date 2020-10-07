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
const int N=1e6+5;
struct node
{
	int u,v,t,c;
	inline bool operator <(const node &rhs)const
	{
		return t==rhs.t?c<rhs.c:t<rhs.t;
	}
} a[N];
int n,m;
int father[N];
inline int find(int x)
{
	return !father[x]?x:father[x]=find(father[x]);
}
struct Edge
{
	int next,to;
	ll dis;
} edge[N];
int head[N],num_edge;
inline void add_edge(int from,int to,ll dis,bool flag=true)
{
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	edge[num_edge].dis=dis;
	head[from]=num_edge;
	if(flag)
		add_edge(to,from,dis,false);
}
ll dis[N];
bitset<N>vis;
inline ll& dijkstra(int s,int t)
{
	priority_queue<pair<int,int> >q;
	memset(dis,0x3f,sizeof(dis));
	q.push(make_pair(dis[s]=0,s));
	vis.reset();
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])
			continue;
//		printf("%d ",u);
		vis.set(u);
		for(int i=head[u]; i; i=edge[i].next)
		{
			int &v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].dis)
			{
				dis[v]=dis[u]+edge[i].dis;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
//	for(int i=1; i<=n; ++i)
//		printf("%lld ",dis[i]);
//	printf("\n\n");
//	printf("%lld\n",dis[0]);
	return dis[t];
}
signed main()
{
	freopen("running.in","r",stdin),freopen("running.out","w",stdout);
	int s,t;
	read(n,m);
	for(int i=1; i<=m; ++i)
		read(a[i].u,a[i].v,a[i].t,a[i].c);
	read(s,t);
	sort(a+1,a+1+m);
	int temperature=0;
	for(int i=1; i<=m&&find(s)!=find(t); ++i)
	{
		int u=a[i].u,v=a[i].v;
		u=find(u),v=find(v);
		if(u==v)
			continue;
//		printf("%d %d (%d,%d)",u,v,t,c);
		father[u]=v;
		temperature=max(temperature,a[i].t);
	}
	for(int i=1; i<=m; ++i)
		if(temperature>=a[i].t)
			add_edge(a[i].u,a[i].v,(ll)a[i].t*a[i].c);
	printf("%d %lld\n",temperature,dijkstra(s,t));
	return 0;
}


