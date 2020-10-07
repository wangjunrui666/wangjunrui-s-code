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
const int N=3e5+5;
int fac[N],inv[N];
struct Edge
{
	int next,to;
} edge[N];
int head[N],num_edge;
inline void add_edge(int from,int to)
{
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	head[from]=num_edge;
}
bitset<N>vis,fa;
inline int quickpow(int a,int b,int p)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=(ll)res*a%p;
		a=(ll)a*a%p;
		b>>=1;
	}
	return res;
}
#define inv(x) (quickpow(fac[x],p-2,p))
int n,m,p;

inline int C(int n,int m)
{
	return 1ll*fac[n]*inv[m]%p*inv[n-m]%p;
}
int sze[N],dp[N];
inline void dfs(int u)
{
	vis.set(u);
	sze[u]=0;
	dp[u]=1;
//	printf("%d ",u);
	for(int i=head[u]; i; i=edge[i].next)
	{
		int &v=edge[i].to;
		dfs(v);
		sze[u]+=sze[v];
		dp[u]=(ll)dp[u]*dp[v]%p*C(sze[u],sze[v])%p;
	}
	++sze[u];
}
inline void work()
{
	read(n,m,p);
	fac[0]=inv[0]=fac[1]=inv[1]=1;
	for(int i=2; i<=n; ++i)
		fac[i]=1ll*fac[i-1]*i%p,inv[i]=1ll*(p-p/i)*inv[p%i]%p;
	for(int i=2; i<=n; ++i)
		inv[i]=1ll*inv[i]*inv[i-1]%p;
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		read(u,v);
		add_edge(v,u);
		fa.set(u);
	}
	for(int i=1; i<=n; ++i)
		if(!fa[i])
			add_edge(0,i);
	dfs(0);
	for(int i=1; i<=n; ++i)
		if(!vis[i])
		{
			printf("0\n");
			return;
		}
//	putchar('\n');
//	for(int i=1; i<=n; ++i)
//		printf("%d %d %d\n",i,sze[i],dp[i]);
	printf("%lld\n",dp[0]);
//	putchar('\n');
//	printf("%d\n",C(2,1));
}
signed main()
{
	freopen("photo.in","r",stdin),freopen("photo.out","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		work();
		vis.reset();
		fa.reset();
		clear(head,0,n,num_edge=0);
	}

	return 0;
}


