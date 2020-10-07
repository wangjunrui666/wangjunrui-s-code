#include <bits/stdc++.h>
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
const int N=2e5+5,mod=998244353;
inline int quickpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=(ll)res*a%mod;
		a=(ll)a*a%mod;
		b>>=1;
	}
	return res;
}
int a[N];
int cnt[N],fac[N],inv[N];
inline int C(int n,int m)//nѡm
{
	if(n==m||m==0)return 1;
	if(m>n)
		return 0;
//	printf("%d %d %lld\n",n,m,(ll)fac[n]*inv[m]%mod*inv[n-m]%mod);
	return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main()
{
	freopen("card.in","r",stdin),freopen("card.out","w",stdout);
	int n,k;
	read(n,k);
	for(int i=1; i<=n; ++i)
	{
		read(a[i]);
		for(int j=30; j>=0; --j)
			if((a[i]>>j)&1)
				++cnt[j];
	}
	fac[0]=inv[0]=fac[1]=inv[1]=1;
	for(int i=2; i<=n; ++i)
		fac[i]=1ll*fac[i-1]*i%mod,inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2; i<=n; ++i)
		inv[i]=1ll*inv[i]*inv[i-1]%mod;
//	printf("%d\n",C(4,3));
//	inv[n]=quickpow(fac[n],mod-2);
//	for(int i=n-1; i>=0; --i)
//		inv[i]=(ll)inv[i+1]*i%mod;
//	for(int i=0; i<=n; ++i)
//		printf(" %d %d %d\n",fac[i],inv[i],quickpow(fac[i],mod-2));
	int ans=0;
	for(int j=30; j>=0; --j)
	{
//		printf(" %d",cnt[j]);
		int sum=0;
		for(int i=1; i<=k&&i<=n; i+=2)
			sum=(sum+(ll)C(cnt[j],i)*C(n-cnt[j],k-i)%mod)%mod;
		ans=(ans+(ll)sum*(1<<j)%mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}


