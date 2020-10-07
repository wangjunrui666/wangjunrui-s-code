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
struct Edge
{
	int next,to;
} edge[N<<1];
int head[N],num_edge;
inline void add_edge(int from,int to)
{
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	head[from]=num_edge;
}
int n,m;
int color[N];
int id[N],cnt;
inline bool dfs(int u,int fa,int col)
{
	id[u]=cnt;
	color[u]=col;
	for(int i=head[u]; i; i=edge[i].next)
	{
		int &v=edge[i].to;
		if(v==fa)
			continue;
		if(color[v])
		{
			if(color[v]==color[u])
				return false;
		}
		else if(!dfs(v,u,3-col))
			return false;
	}
	return true;
}
bitset<N>vis;
int dis[N];
int maxx[N];
inline void bfs(int s)
{
	queue<int>q;
	q.push(s);
	vis.set(s);
	clear(dis,1,n,0);
	while(!q.empty())
	{
		int u=q.front();
//		printf("%d ",u);
		q.pop();
		for(int i=head[u]; i; i=edge[i].next)
		{
			int &v=edge[i].to;
			if(!vis[v])
			{
				vis.set(v);
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	for(int i=1; i<=n; ++i)
		maxx[id[i]]=max(maxx[id[i]],dis[i]);
	vis.reset();
//	putchar('\n');
}
signed main()
{
	freopen("merge.in","r",stdin),freopen("merge.out","w",stdout);
	read(n,m);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		read(u,v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1; i<=n; ++i)
		if(!id[i])
		{
			++cnt;
			if(!dfs(i,0,1))
			{
				printf("-1\n");
				return 0;
			}
		}
	for(int i=1; i<=n; ++i)
		bfs(i);
	int ans=0;
	for(int i=1; i<=cnt; ++i)
		ans+=maxx[i];
	printf("%d\n",ans);
	return 0;
}

