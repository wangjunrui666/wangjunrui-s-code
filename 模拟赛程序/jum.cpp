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
ll g=0,a[N];
inline ll gcd(ll m,ll n)
{
	if(n==0)
		return m;
	return gcd(n,m%n);
}
int n,m;
inline void work()
{
	ll pos;
	read(pos);
	if(pos%g==0||2*pos%g==a[1])
		printf("Yes\n");
	else
		printf("No\n");
}
signed main()
{
	freopen("jum.in","r",stdin),freopen("jum.out","w",stdout);
	read(n,m);
	for(int i=1; i<=n; ++i)
		read(a[i]);
	for(int i=2; i<=n; ++i)
		g=gcd(g,a[i]-a[1]);
	g<<=1;
	while(m--)
		work();
	return 0;
}


