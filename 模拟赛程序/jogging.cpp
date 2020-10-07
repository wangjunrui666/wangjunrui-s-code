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
int in[N];
int n,ml,md;
//bitset<N>vis;
//inline void dfs(int u,int w,int root)
//{
//	vis.set(u);
//	for(auto v:g1[u])
//	{
//		g[root].push_back(make_pair(v.first,w+v.second));
//		dfs(v.first,w+v.second,root);
//	}
//}
struct Edge
{
	int next,to,dis;
} edge[N<<2];
int head[N],num_edge;
inline void add_edge(int from,int to,int dis)
{
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	edge[num_edge].dis=dis;
	++in[to];
	head[from]=num_edge;
}
ll dis[N];
signed main()
{
	freopen("jogging.in","r",stdin),freopen("jogging.out","w",stdout);
	read(n,ml,md);
	for(int i=1; i<=ml; ++i)
	{
		int u,v,w;
		read(u,v,w);
		if(u>v)
			swap(u,v);
		add_edge(u,v,w);
	}
	for(int i=1; i<=md; ++i)
	{
		int u,v,w;
		read(u,v,w);
		if(u>v)
			swap(u,v);
		add_edge(u,v,-w);
	}
//	for(int i=1; i<=n; ++i)
//		if(!vis[i])
//			dfs(i,0,i);
//	putchar('\n');
//	for(int u=1; u<=n; ++u)
//		for(auto v:g[u])
//			printf("%d %d %d\n",u,v.first,v.second);
//	for(int i=1; i<=n; ++i)
//		printf("%d ",in[i]);
//	putchar('\n');
	queue<int>q;
	for(int i=1; i<=n; ++i)
		if(!in[i])
			q.push(i);
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
//		printf("%d:",u);
		for(int i=head[u]; i; i=edge[i].next)
		{
			int &v=edge[i].to;
//			printf(" %d",v);
			if(dis[v]>dis[u]+edge[i].dis)
				dis[v]=dis[u]+edge[i].dis;
			if(!(--in[v]))
				q.push(v);
		}
//		putchar('\n');
	}
//	putchar('\n');
	printf("%lld\n",dis[n]);
	if(dis[n]<0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
