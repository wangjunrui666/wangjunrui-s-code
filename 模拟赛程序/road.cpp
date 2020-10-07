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
#define calc(x,y) ((x-1)*m+y)
int n,m,h[N],w[N];
const int dx[4]= {1,-1,0,0};
const int dy[4]= {0,0,1,-1};
vector<int>g[N],newg[N];
int low[N],dfn[N],dfstime;
int belong[N],color;
ll point[N];
int st[N],top;
int in[N];
ll dis[N];
inline void tarjan(int u)
{
	low[u]=dfn[u]=++dfstime;
	st[++top]=u;
	for(auto v:g[u])
	{
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!belong[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		belong[u]=++color;
		point[color]=w[u];
		if(st[top]!=u)
		{
			while(st[top]!=u)
			{
				belong[st[top]]=color;
				point[color]+=w[st[top--]];
			}
			point[color]*=2;
		}
		--top;
	}
}
signed main()
{
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	read(n,m);
	for(int i=1; i<=n*m; ++i)
		read(h[i]);
	for(int i=1; i<=n*m; ++i)
		read(w[i]);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			for(int d=0; d<4; ++d)
			{
				int x=i+dx[d],y=j+dy[d];
				if(x>=1&&x<=n&&y>=1&&y<=m&&h[calc(i,j)]>=h[calc(x,y)])
				{
					g[calc(i,j)].push_back(calc(x,y));
//					printf("(%d,%d) (%d,%d)\n",i,j,x,y);
				}
			}
	for(int i=1; i<=n*m; ++i)
		if(!dfn[i])
			tarjan(i);
	for(int u=1; u<=n*m; ++u)
		for(auto v:g[u])
			if(belong[u]!=belong[v])
			{
				newg[belong[u]].push_back(belong[v]);
				++in[belong[v]];
//				printf("%d %d\n",belong[u],belong[v]);
			}
	queue<int>q;
	for(int i=1; i<=color; ++i)
		if(!in[i])
		{
			q.push(i);
			dis[i]=point[i];
		}
//	for(int i=1; i<=color; ++i)
//		printf("%lld ",point[i]);
//	putchar('\n');
	ll ans=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		ans=max(ans,dis[u]);
		for(auto v:newg[u])
		{
			dis[v]=max(dis[v],dis[u]+point[v]);
			if(!(--in[v]))
				q.push(v);
		}
	}
	printf("%lld\n",ans);
	return 0;
}


