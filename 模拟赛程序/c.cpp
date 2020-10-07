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
const int N=55,INF=0x3f3f3f3f;
int n,m;
ll dp[N][N][N*N*2];
bitset<N*N*2>vis[N][N];
int a[N][N];
inline ll dfs(int x,int y,int val)
{
	if(x<1||y<1||val<0)
		return 1e18;
	if(vis[x][y][val])
		return dp[x][y][val];
	vis[x][y].set(val);
	ll &ans=dp[x][y][val];
	return ans=min(dfs(x-1,y,val-a[x][y]),dfs(x,y-1,val-a[x][y]))+(n+m-1)*a[x][y]*a[x][y];
}
signed main()
{
	freopen("c.in","r",stdin),freopen("c.out","w",stdout);
	read(n,m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			read(a[i][j]);
	memset(dp[1][1],INF,sizeof(dp[1][1]));
	dp[1][1][a[1][1]]=(n+m-1)*a[1][1]*a[1][1];
	vis[1][1].set();
	ll ans=1e18;
	for(int i=0; i<=(n+m-1)*50; ++i)
		ans=min(ans,dfs(n,m,i)-i*i);
//	printf(" %d\n",dp[1][1][a[1][1]]);
//	for(int i=1; i<=n; ++i)
//		for(int j=1; j<=m; ++j)
//		{
//			printf("%d %d\n",i,j);
//			for(int k=0; k<=10; ++k)
//				printf(" %lld",dp[i][j][k]);
//			putchar('\n');
//		}
	printf("%lld\n",ans);
	return 0;
}


