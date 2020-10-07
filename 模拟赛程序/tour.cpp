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
const int N=1505;
char str[N][N];
int n,cnt[N];
bitset<N>a[N];
signed main()
{
	freopen("tour.in","r",stdin),freopen("tour.out","w",stdout);
	read(n);
	for(int i=1; i<=n; ++i)
		scanf("%s",str[i]+1);
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
			if(a[i][j]=str[i][j]-'0')
				++cnt[i];
	}
	ll ans=0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			if(a[i][j])
				ans+=(ll)(cnt[i]-1)*(cnt[j]-1);
//	printf("%lld\n",ans);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			if(a[i][j])
				ans-=(a[i]&a[j]).count();
	printf("%lld\n",ans);
	return 0;
}


