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
const int N=1e6+5;
int idx,n,a[N],b[N];
char str[N];
int cnt[N][2];
signed main()
{
	freopen("puzzle.in","r",stdin),freopen("puzzle.out","w",stdout);
	read(idx,n);
	scanf("%s",str+1);
	int tot=0;
	for(int i=1; i<=n; ++i)
	{
		if(str[i]=='1')
			++tot;
		++a[tot];
	}
	tot=0;
	for(int i=n; i>=1; --i)
	{
		if(str[i]=='1')
			++tot;
		++b[tot];
	}
	reverse(b+1,b+1+tot);
//	for(int i=1; i<=n; ++i)
//		printf("%d %d\n",a[i],b[i])l;
	ll ans=0;
	for(int i=1; i<=tot; ++i)
	{
		cnt[i][0]=cnt[i-1][0];
		cnt[i][1]=cnt[i-1][1];
		cnt[i][i&1]+=b[i];
		ans+=(ll)cnt[i][i&1]*a[i]-a[i]-b[i]+1;
	}
	printf("%lld\n",ans);
	return 0;
}


