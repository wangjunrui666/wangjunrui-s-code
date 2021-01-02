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
const int N=1e6+5,mod=1e9+7,inv2=(mod+1)>>1;
int n,m,q,h[N],l[N];
inline int times(int a,int b)
{
	return (int)((ll)a*b%mod);
}
inline int add(int a,int b)
{
	a+=b;
	if(a>=mod)
		a-=mod;
	return a;
}
signed main()
{
	freopen("game.in","r",stdin),freopen("game.out","w",stdout);
	read(n,m,q);
	for(int i=1; i<=n; ++i)
		h[i]=1;
	for(int i=1; i<=m; ++i)
		l[i]=1;
	while(q--)
	{
		char opt[3];
		scanf("%s",opt);
		int x,y;
		read(x,y);
		if(opt[0]=='R')
			h[x]=times(h[x],y);
		else
			l[x]=times(l[x],y);
	}
	int sum=0,cnt=0;
	for(int i=1; i<=m; ++i)
		sum=add(sum,l[i]);
	for(int i=1; i<=m; ++i)
		cnt=add(cnt,times(l[i],i));
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		ans=add(ans,times(add(times(times(i-1,m),sum),cnt),h[i]));
	}
	printf("%d\n",ans);
	return 0;
}


