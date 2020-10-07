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
const int N=5005,mod=786433;
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
int n,k;
int dp[N][N],f[N],sze[N];
inline void add(int &x,int y)
{
	x+=y;
	if(x>=mod)
		x-=mod;
}
inline void dfs(int u,int fa)
{
	sze[u]=1;
	dp[u][1]=1;
	for(int i=head[u]; i; i=edge[i].next)
	{
		int &v=edge[i].to;
		if(v==fa)
			continue;
		dfs(v,u);
		for(int j=1; j<=sze[u]; ++j)
			for(int kk=1; kk<=sze[v]; ++kk)
			{
				int res=(ll)dp[u][j]*dp[v][kk]%mod;
				add(f[j+kk],res);
				if(kk>=k)
					add(f[j],res);
			}
		sze[u]+=sze[v];
		for(int j=1; j<=sze[u]; ++j)
			dp[u][j]=f[j];
		clear(f,1,sze[u],0);
	}
}
signed main()
{
	freopen("cut.in","r",stdin),freopen("cut.out","w",stdout);
	read(n,k);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		read(u,v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	int ans=0;
	for(int i=k; i<=n; ++i)
		add(ans,dp[1][i]);
	printf("%d\n",ans);
	return 0;
}


