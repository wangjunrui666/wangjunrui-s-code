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
const int N=5e5+5;
int a[N];
int mul[N],prime[N],tot;
bitset<N>vis;
inline void getprime(int n)
{
	mul[1]=1;
	for(int i=2; i<=n; ++i)
	{
		if(!vis[i])
		{
			prime[++tot]=i;
			mul[i]=-1;
		}
		for(int j=1; j<=tot; ++j)
		{
			if(prime[j]*i>n)
				break;
			vis.set(prime[j]*i);
			if(i%prime[j])
				mul[i*prime[j]]=-mul[i];
			else
			{
				mul[i*prime[j]]=0;
				break;
			}
		}
	}
}
int s[N];
inline ll g(int i)
{
	return (ll)s[i]*(s[i]-1)/2;
}
ll ans;
inline void add(int pos)
{
	ans+=(ll)s[pos]*mul[pos];
	++s[pos];
}
inline void del(int pos)
{
	--s[pos];
	ans-=(ll)s[pos]*mul[pos];
}
inline void work(int pos)
{
	if(vis[pos])
	{
		for(int i=1; i*i<=a[pos]; ++i)
			if(a[pos]%i==0)
			{
				del(i);
				if(i*i!=a[pos])
					del(a[pos]/i);
			}
		vis[pos]=false;
	}
	else
	{
		for(int i=1; i*i<=a[pos]; ++i)
			if(a[pos]%i==0)
			{
				add(i);
				if(i*i!=a[pos])
					add(a[pos]/i);
			}
		vis[pos]=true;
	}
}
signed main()
{
	freopen("pair.in","r",stdin),freopen("pair.out","w",stdout);
	getprime(5e5);
	int n,m;
	read(n,m);
	for(int i=1; i<=n; ++i)
		read(a[i]);
	vis.reset();
	for(int i=1; i<=m; ++i)
	{
		int pos;
		read(pos);
		work(pos);
		printf("%lld\n",ans);
	}
	return 0;
}


