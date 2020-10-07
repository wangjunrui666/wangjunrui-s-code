#include <bits/stdc++.h>
#define int long long
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
const int N=1e6+5,M=10*N,INF=0x3f3f3f3f;
struct Edge
{
	int next,to,dis;
} edge[M];
int head[N],num_edge;
inline void add_edge(int from,int to,int dis)
{
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	edge[num_edge].dis=dis;
	head[from]=num_edge;
}
int n,maxc;
inline void work()
{
	int minn=INF,now=0;
	for(int i=1; i<=n; ++i)
	{
		int c,v;
		read(c,v);
		minn=min(minn,v);
		now+=v;
		printf("%lld ",now);
	}
	putchar('\n');
}
bitset<N>vis;
int dis[N];
signed main()
{
	freopen("bus.in","r",stdin),freopen("bus.out","w",stdout);
	read(n,maxc);
	if(maxc==1)
	{
		work();
		return 0;
	}
	for(int i=0; i<n; ++i)
	{
		int c,v;
		read(c,v);
		for(int j=1; i+j*c<=n; ++j)
			add_edge(i,i+j*c,j*v);
	}
	priority_queue<pair<int,int> >q;
	memset(dis,INF,sizeof(dis));
	q.push(make_pair(dis[0]=0,0));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])
			continue;
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
	for(int i=1; i<=n; ++i)
		if(dis[i]>=dis[n+1])
			printf("-1 ");
		else
			printf("%lld ",dis[i]);
	putchar('\n');
	return 0;
}


