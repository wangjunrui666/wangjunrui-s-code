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
const int N=55,M=505;
int n,m,a[N][N];
int sum[N][N];
int dp[N][N][M];
signed main()
{
	freopen("skill.in","r",stdin),freopen("skill.out","w",stdout);
	read(n,m);
	for(int i=1; i<=n; ++i)
	{

		for(int j=i; j<=n; ++j)
			read(a[i][j]);
	}
	memset(dp,~0x3f3f3f3f,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=1; i<=n; ++i)
		for(int j=i; j<=n; ++j)
			sum[i][j]=sum[i-1][j]+a[i][j];
//	for(int i=1; i<=n; ++i)
//	{
//		for(int j=i; j<=n; ++j)
//			printf("%d ",sum[i][j]);
//		putchar('\n');
//	}

	for(int i=1; i<=n; ++i)
	{
		dp[i][0][0]=0;
		for(int j=1; j<=m; ++j)
			for(int k=0; k<=min(j,i); ++k)
			{
				for(int l=max(0,k-1); l<=min(j-k,i-1); ++l)
					dp[i][k][j]=max(dp[i][k][j],dp[i-1][l][j-k]);
				dp[i][k][j]+=sum[k][i];
			}
	}
//	for(int i=1; i<=n; ++i)
//	{
//
//		for(int j=1; j<=i; ++j)
//		{
//			for(int k=1; k<=m; ++k)
//				printf("dp[%d][%d][%d]=%d ",i,j,k,dp[i][j][k]);
//			putchar('\n');
//		}
//		putchar('\n');
//	}

	int ans=0;
	for(int i=0; i<=n; ++i)
		ans=max(ans,dp[n][i][m]);
	printf("%d\n",ans);
	return 0;
}


