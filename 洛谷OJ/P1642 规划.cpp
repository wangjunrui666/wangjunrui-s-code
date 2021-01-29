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
const int N=1005;
int n,m;
struct Edge
{
	int next,to;
} edge[N*2];
int head[N],num_edge;
inline void add_edge(int from,int to)
{
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	head[from]=num_edge;
}
struct node
{
	int a,b;
} a[N];
double dp[N][N];
int dfstime,size[N],id[N];
inline void dfs(int u,int fa)
{
	size[u]=1;
	id[++dfstime]=u;
	for(int i=head[u]; i; i=edge[i].next)
	{
		int &v=edge[i].to;
		if(v==fa)
			continue;
		dfs(v,u);
		size[u]+=size[v];
	}
}
inline bool solve(int root,double val)
{
	dfstime=0;
	dfs(root,0);
	memset(dp,~(127/3),sizeof(dp));
	dp[1][0]=0;
	for(int i=1; i<=n; ++i)
		for(int j=0; j<=m; ++j)
		{
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]+a[id[i]].a-val*a[id[i]].b);
			if(j+size[i]<=m)
				dp[i+size[i]][j+size[i]]=max(dp[i+size[i]][j+size[i]],dp[i][j]);
		}
//	for(int i=1; i<=n; ++i)
//	{
//		for(int j=0; j<=m; ++j)
//			printf("%lf ",dp[i][j]);
//		puts("\n");
//	}
	return dp[n+1][m]>=0;
}
inline bool check(double val)
{
	for(int i=1; i<=n; ++i)
		if(solve(i,val))
			return true;
	return false;
}
signed main()
{
	read(n,m);
	for(int i=1; i<=n; ++i)
		read(a[i].a);
	for(int i=1; i<=n; ++i)
		read(a[i].b);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		read(u,v);
		add_edge(u,v);
		add_edge(v,u);
	}
	double l=0,r=1e5,ans=0;
//	printf("%d\n",solve(1,0));
	while(r-l>=1e-6)
	{
		double mid=(l+r)/2;
		if(check(mid))
			l=ans=mid;
		else
			r=mid;
	}
	printf("%.1lf\n",ans);
	return 0;
}


