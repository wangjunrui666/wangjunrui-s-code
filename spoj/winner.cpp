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
const int N=20,M=1e6+5,mod=1e9+7;
int n,m,id;
int mp[N][N];
int dp[(1<<15)+5];
ll f[(1<<15)+5],g[(1<<15)+5];
int power[N*N];
signed main()
{
	freopen("winner.in","r",stdin);
	freopen("winner.out","w",stdout);
	read(n,m,id);
	power[0]=1;
	for(int i=1; i<=n*n; ++i)
		power[i]=power[i-1]*2%mod;
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		read(u,v);
		if(u>v)
			swap(u,v);
		mp[u][v]=1;
	}
	int res=0;
//	for(int i=1; i<=n; ++i)
//	{
//		for(int j=1; j<=n; ++j)
//			printf(" %d ",mp[i][j]);
//		putchar('\n');
//	}
//	printf("%d\n",res);
	for(int S=1; S<(1<<n); ++S)
	{
		for(int i=1; i<=n; ++i)
			for(int j=i+1; j<=n; ++j)
				if(((S>>(i-1))&1)&&((S>>(j-1))&1)&&mp[i][j])
					++dp[S];
	}
	f[1]=g[2]=1;
	for(int S=1; S<(1<<n); ++S)
	{
		if(S&1)
		{
			f[S]=power[dp[S]];
			for(int T=S&(S-1); T; T=S&(T-1))
				f[S]=(f[S]-f[T]*power[dp[S^T]]%mod+mod)%mod;
		}
		if(S&2)//
		{
			g[S]=power[dp[S]];
			for(int T=S&(S-1); T; T=S&(T-1))
				g[S]=(g[S]-g[T]*power[dp[S^T]]%mod+mod)%mod;
		}
	}
//	for(int S=1; S<(1<<n); ++S)
//		printf("f=%lld g=%lld\n",f[S],g[S]);
//	putchar('\n');
//	for(int S=1; S<(1<<n); ++S)
//		printf("%d ",dp[S]);
//	putchar('\n');
	ll ans=0;
	for(int S=1; S<(1<<n); ++S)
	{
		int CS=((1<<n)-1)^S;
//		printf(" %d %d\n",S,CS);
		for(int T=CS; T; T=CS&(T-1))
		{
//			printf("%d %d %lld %lld\n",S,T,f[S],g[T]);
			if(dp[S]+dp[T]==dp[S|T])
				(ans+=f[S]*g[T]%mod*power[dp[CS^T]]%mod)%=mod;
		}
	}
//	printf("%lld\n",ans);
	printf("%lld\n",(power[m]-ans+mod)%mod);
	return 0;
}


