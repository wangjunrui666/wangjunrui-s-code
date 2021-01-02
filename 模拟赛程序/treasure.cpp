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
const int N=105;
int n,m;
bool dp[2][65][N][N];
bool f[N],g[N];
signed main()
{
	freopen("treasure.in","r",stdin),freopen("treasure.out","w",stdout);
	read(n,m);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		read(u,v,w);
		if(w)
			dp[1][0][u][v]=true;
		else
			dp[0][0][u][v]=true;
	}
	for(int len=1; len<=61; ++len)
		for(int k=1; k<=n; ++k)
			for(int i=1; i<=n; ++i)
				for(int j=1; j<=n; ++j)
					for(int d=0; d<2; ++d)
						dp[d][len][i][j]=(dp[d][len][i][j])||(dp[d][len-1][i][k]&&dp[d^1][len-1][k][j]);
	ll ans=0;
	bool flag=false;
	f[1]=1;
	for(int len=61; len>=0; --len)
	{
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
				g[j]=g[j]||(dp[flag][len][i][j]&&f[i]);
		bool tag=false;
		for(int i=1; i<=n; ++i)
			if(g[i])
				tag=true;
		if(tag)
		{
			flag^=1;
			ans|=(1ll<<len);
//			for(int i=1; i<=n; ++i)
//				f[i]=g[i];
			memcpy(f,g,sizeof(g));
		}
		memset(g,0,sizeof(g));
//		printf("%d:\n",len);
//		for(int i=1; i<=n; ++i)
//			printf("%d ",f[i]);
//		putchar('\n');
	}
	if(ans>1e18)
		printf("-1\n");
	else
		printf("%lld\n",ans);
	return 0;
}


