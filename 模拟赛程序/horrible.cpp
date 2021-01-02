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
const int N=1e6+5,mod=998244353;
#define div divote
int n,m,c[N],div=1,fac[N]= {1};
inline int times(int a,int b)
{
	return (int)((ll)a*b%mod);
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
signed main()
{
	freopen("horrible.in","r",stdin),freopen("horrible.out","w",stdout);
	read(m);
	for(int i=1; i<=m; ++i)
	{
		read(c[i]);
		n+=c[i];
	}
	for(int i=1; i<=n; ++i)
		fac[i]=times(fac[i-1],i);
	for(int i=1; i<=m; ++i)
		div=times(div,fac[c[i]]);
	printf("%d\n",times(fac[n],quickpow(div,mod-2)));
	return 0;
}


