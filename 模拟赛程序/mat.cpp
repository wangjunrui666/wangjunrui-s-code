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
const int N=15;
int ans=0;
int n,m,a[N][N];
inline void dfs2()
{
	int res=0;
	for(int j=1; j<=m; ++j)
	{
		int now=0;
		for(int add=0; add<3; ++add)
		{
			int sum=0;
			for(int i=1; i<=n; ++i)
				if(a[i][j]+add==3||a[i][j]+add==6||a[i][j]+add==9||a[i][j]+add==12)
					++sum;
			now=max(now,sum);
		}
		res+=now;
	}
	if(res>ans)
		ans=res;
}
inline void dfs1(int pos)
{
	for(int i=0; i<3; ++i)
	{
		int now=0;
		for(int j=1; j<=m; ++j)
			if(a[pos][j]<=12&&a[pos][j]+i>12)
				++now;
		for(int j=1; j<=m; ++j)
			a[pos][j]+=i;
		if(pos==n)
			dfs2();
		else
			dfs1(pos+1);
		for(int j=1; j<=m; ++j)
			a[pos][j]-=i;
	}
}
signed main()
{
	freopen("mat.in","r",stdin),freopen("mat.out","w",stdout);
	read(n,m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			read(a[i][j]);
	dfs1(1);
	printf("%d\n",ans);
	return 0;
}


