#include <cstdio>
#include <map>
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
template<typename T>
inline void clear(T*array,int l,int r,int val)
{
	memset(&array[l],val,sizeof(T)*(r-l+1));
}
using namespace std;
ll p,k;
map<int,int>mp;
inline ll quickpow(ll a,ll b,ll mod=p)
{
	ll res=1;
	while(b)
	{
		if(b&1)
			res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
inline ll solve(ll n)
{
	if(!n)
		return 1;
	if(n&1)
		return ((1+quickpow(k,n/2+1))%p*solve(n/2)%p)%p;
	else
		return ((1+quickpow(k,n/2+1))%p*solve(n/2-1)+quickpow(k,n/2)%p)%p;
}
signed main()
{
	ll n;
	freopen("split.in","r",stdin),freopen("split.out","w",stdout);
	read(k),read(n),read(p);
	k%=p;
	printf("%lld\n",solve(n-2));
	return 0;
}


