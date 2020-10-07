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
const int N=1e5+5;
inline int quickpow(int a,int b,int mod)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
bitset<N>vis;
int n,m;
inline void solve(int val)
{
	for(int i=val; i<=n; i+=val)
		vis.reset(i);
}
inline int getphi(int val)
{
	int res=val;
	for(int i=2; i*i<=val; ++i)
		if(val%i==0)
		{
			res=res/i*(i-1);
			solve(i);
			do
				val/=i;
			while(val%i==0);
		}
	if(val>1)
	{
		res=res/val*(val-1);
		solve(val);
	}
	return res;
}
inline bool check(int val)
{
	for(int i=2; i*i<=m; ++i)
		if(m%i==0)
		{
//			printf("%d:%d %d ",val,i,m/i);
//			printf("%d %d\n",quickpow(val,i,n),quickpow(val,m/i,n));
			if(quickpow(val,i,n)==1||quickpow(val,m/i,n)==1)
				return true;
		}
	return false;
}
signed main()
{
	freopen("math.in","r",stdin),freopen("math.out","w",stdout);
	vis.set();
	read(n);
	m=getphi(n);
	bool flag=true;
//	printf("%d %d\n",n,m);
//	printf("%d\n",quickpow(1,2,n));
	for(int i=1; i<=n; ++i)
		if(vis[i]&&!check(i))
		{
			printf("%d\n",i);
			flag=false;
		}
	if(flag)
		printf("-1\n");
	return 0;
}


