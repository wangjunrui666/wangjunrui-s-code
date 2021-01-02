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
const int N=5e5+5,mod=1e9+7,lim=1e5;
inline void add(int &a,int b)
{
	a+=b;
	if(a>=mod)
		a-=mod;
}
inline int times(int a,int b)
{
	int res=0;
	while(b)
	{
		if(b&1)
			add(res,a);
		add(a,a);
		b>>=1;
	}
	return res;
}
inline int quickpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=times(res,a);
		a=times(a,a);
		b>>=1;
	}
	return res;
}
int fac[N],inv[N];
inline int C(int n,int m)
{
	if(n<m)
		return 0;
	return times(fac[n],times(inv[n],inv[n-m]));
}
int n,cnt[15];
int f[5005][5005];
int dp[2][N];
signed main()
{
	read(n);
	for(int i=1; i<=n; ++i)
	{
		int val;
		read(val);
		++cnt[val];
	}
	fac[0]=inv[0]=1;
	for(int i=1; i<=lim; ++i)
		fac[i]=times(fac[i-1],i);
	inv[lim]=quickpow(fac[lim],mod-2);
	for(int i=lim-1; i>=1; --i)
		inv[i]=times(inv[i+1],i+1);
	f[0][0]=1;
	int sum=0;
	for(int i=1; i<=10; ++i)
		if(i!=7)
		{
			if(cnt[i])
			{
				sum+=cnt[i];
				for(int j=1; j<=sum; ++j)
				{
					for(int k=1; k<=j&&k<=cnt[i]; ++k)
						add(f[i][j],times(f[i-1][j-k],C(j,k)));
				}
			}
			else
				for(int j=0; j<=sum; ++j)
					add(f[i][j],f[i-1][j]);
		}
	sum+=cnt[0];
	if(cnt[0])
	{
		sum+=cnt[0];
		for(int i=1; i<=sum; ++i)
			for(int j=1; j<=i&&j<=cnt[0]; ++j)
			{
				add(dp[0][i],times(f[10][i-j],C(i-1,j)));
				add(dp[1][i],times(f[10][i-j],C(i,j)));
			}
	}
	else
	{
		for(int i=0; i<=sum; ++i)
			add(dp[0][i],f[10][i]);
	}
	return 0;
}


