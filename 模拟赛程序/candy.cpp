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
const int N=405,mod=1e9+7;
int f[N][N],n,m;
int g[N][N];
struct node
{
	int l,r;
} a[N];
inline void add(int &x,int y)
{
	x+=y;
	if(x>=mod)
		x-=mod;
}
signed main()
{
	freopen("candy.in","r",stdin),freopen("candy.out","w",stdout);
	read(n,m);
	for(int i=1; i<=n; ++i)
		read(a[i].l);
	for(int i=1; i<=n; ++i)
		read(a[i].r);
	for(int i=1; i<=400; ++i)
	{
		g[i][0]=1;
		for(int j=1; j<=400; ++j)
			g[i][j]=(int)((ll)g[i][j-1]*i%mod);
		for(int j=0; j<=400; ++j)
			add(g[i][j],g[i-1][j]);
	}
	f[0][0]=1;
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<=m; ++j)
			for(int k=0; k<=j; ++k)
				add(f[i][j],(int)((ll)f[i-1][j-k]*((g[a[i].r][k]-g[a[i].l-1][k]+mod)%mod)%mod));
	}
//	for(int i=1; i<=n; ++i)
//	{
//		for(int j=0; j<=m; ++j)
//			printf("%d ",f[i][j]);
//		putchar('\n');
//	}
	printf("%d\n",f[n][m]);
	return 0;
}


