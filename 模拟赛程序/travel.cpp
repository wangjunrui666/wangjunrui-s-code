#include <bits/stdc++.h>
#define int ll
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
int n,m;
struct Edge
{
	int next,to,dis;
} edge[N];
int head[N],num_edge;
inline void add_edge(int from,int to,int dis)
{
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	edge[num_edge].dis=dis;
	head[from]=num_edge;
}
inline int calc(const vector<int>&g,int w)
{
	int i=0;
	for(; i<g.size()&&g[i]<w; ++i);

	if(i==g.size()||g[i]!=w)
		return w;
	for(; i<g.size()&&g[i+1]==g[i]+1; ++i);
	if(i==g.size())
		return g[i-1]+1;
	else
		return g[i]+1;
}
vector<int>link[N];
int dis[N];
bitset<N>vis;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read(n,m);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		read(u,v,w);
		add_edge(u,v,w);
	}
	for(int i=1; i<=n; ++i)
	{
		int cnt;
		read(cnt);
		for(int j=1; j<=cnt; ++j)
		{
			int tim;
			read(tim);
			link[i].push_back(tim);
		}
		sort(link[i].begin(),link[i].end());
	}
	priority_queue<pair<int,int> >q;
//	clear(dis,1,n,0x3f);
	memset(dis,0x3f,sizeof(dis));
	q.push(make_pair(dis[1]=0,1));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u]=true;
//		printf("%d:\n",u);
		for(int i=head[u]; i; i=edge[i].next)
		{
			int &v=edge[i].to,w=calc(link[v],dis[u]+edge[i].dis);
//			printf("%d %d %d\n",v,dis[u]+edge[i].dis,w);
			if(w<dis[v])
			{
				dis[v]=w;
				q.push(make_pair(-w,v));
			}
		}
	}
	printf("%lld\n",dis[n]);
	return 0;
}


