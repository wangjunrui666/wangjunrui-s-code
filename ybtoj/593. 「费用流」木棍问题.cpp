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
const int N=40*40*3+5;
const int INF=0x3f3f3f3f;
struct Edge
{
	int next,to;
	int flow,cap;
	int cost;
} edge[N*N];
int head[N],num_edge=1;
int T;
int n,m,A,B;
inline void add_edge(int from,int to,int cap,int cost,bool flag=true)
{
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	edge[num_edge].cap=cap;
	edge[num_edge].flow=0;
	edge[num_edge].cost=cost;
	head[from]=num_edge;
	if(flag)
	{
		add_edge(to,from,0,-cost,false);
//		printf("%d %d %d\n",from,to,cap);
	}
}
#define s 0
#define ss (n*m*3+1)
#define t (n*m*3+2)
int dis[N],cur[N];
bool exist[N];
inline bool spfa()
{
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(exist,false,sizeof(exist));
	for(re int i=s; i<=t; ++i)
		cur[i]=head[i];
	std::queue<int>q;
	q.push(s);
	dis[s]=0;
	exist[s]=true;
	while(!q.empty())
	{
		int u=q.front();
		printf("%d\n",u);
		q.pop();
		exist[u]=false;
		for(re int i=head[u]; i; i=edge[i].next)
		{
			int &v=edge[i].to;
//			printf("%d\n",v);
			if(edge[i].cap>edge[i].flow&&dis[v]>dis[u]+edge[i].cost)
			{
				dis[v]=dis[u]+edge[i].cost;
				if(!exist[v])
				{
					q.push(v);
					exist[v]=true;
				}
			}
		}
	}
	for(int i=s; i<=t; ++i)
		printf("%d ",dis[i]);
	putchar('\n');
	return dis[t]<0x3f3f3f3f;
}
ll ans=0;
inline int dinic(int u,int flow)
{
	if(u==t)
	{
		ans+=dis[t]*flow;
		return flow;
	}
	exist[u]=true;
	int res=0;
	for(int &i=cur[u]; i; i=edge[i].next)
	{
		int &v=edge[i].to;
		if(!exist[v]&&dis[v]==dis[u]+edge[i].cost&&edge[i].cap>edge[i].flow)
		{
			int f=dinic(v,std::min(flow,edge[i].cap-edge[i].flow));
			if(f)
			{
				res+=f;
				edge[i].flow+=f;
				edge[i^1].flow-=f;
				flow-=f;
				if(!flow)
				{
					exist[u]=false;
					break;
				}
			}
		}
	}
	return res;
}
char str[45][45];
inline bool check(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=m&&str[x][y]=='0';
}
inline int calc(int x,int y)
{
	return (x-1)*m+y;
}
inline void work(int val)
{
	add_edge(s,ss,val,0);
	int flow=0;
	ans=0;
	while(spfa())
	{
		printf("ok:");
		int now=dinic(s,INF);
		flow+=now;
		printf("%d\n",now);
		ans+=dis[t]*now;
	}
	printf("flow=%d ans=%lld\n",flow,ans);
	num_edge-=2;
	for(int i=1; i<=num_edge; ++i)
		edge[i].flow=0;
}
signed main()
{
	read(T,n,m,A,B);
	for(int i=1; i<=n; ++i)
		scanf("%s",str[i]+1);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			printf("%d\n",calc(i,j));
			if(str[i][j]=='0')
			{
				if((i+j)&1)
				{
					add_edge(ss,calc(i,j),1,0);
					add_edge(ss,calc(i,j),1,A);
					add_edge(ss,calc(i,j),1,2*A);
					add_edge(ss,calc(i,j),1,3*A);
					add_edge(calc(i,j),calc(i,j)+n*m,1,0);
					add_edge(calc(i,j),calc(i,j)+n*m,1,B-A);
					add_edge(calc(i,j),calc(i,j)+2*n*m,1,0);
					add_edge(calc(i,j),calc(i,j)+2*n*m,1,B-A);

					if(check(i,j-1))
						add_edge(calc(i,j)+n*m,calc(i,j-1)+n*m,1,0);
					if(check(i,j+1))
						add_edge(calc(i,j)+n*m,calc(i,j+1)+n*m,1,0);
					if(check(i-1,j))
						add_edge(calc(i,j)+2*n*m,calc(i-1,j)+2*n*m,1,0);
					if(check(i+1,j))
						add_edge(calc(i,j),2*n*m,calc(i+1,j)+2*n*m,1,0);
				}
				else
				{
					add_edge(calc(i,j),t,1,0);
					add_edge(calc(i,j),t,1,A);
					add_edge(calc(i,j),t,1,2*A);
					add_edge(calc(i,j),t,1,3*A);
					add_edge(calc(i,j)+n*m,calc(i,j),1,0);
					add_edge(calc(i,j)+n*m,calc(i,j),1,B-A);
					add_edge(calc(i,j)+2*n*m,calc(i,j),1,0);
					add_edge(calc(i,j)+2*n*m,calc(i,j),1,B-A);
				}
			}
		}

	int q;
	read(q);
	work(q);
//	for(int i=1; i<=q; ++i)
//	{
//		work(i);
//	}
	return 0;
}


