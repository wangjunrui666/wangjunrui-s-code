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
const int N=2e5+5;
int c[N];
inline void update(int pos,int val)
{
	for(int i=pos; i<=2e5; i+=lowbit(i))
		c[i]+=val;
}
inline int query(int pos)
{
	if(pos<=0)
		return 0;
	int res=0;
	for(int i=pos; i; i-=lowbit(i))
		res+=c[i];
	return res;
}
int n,S;
inline int query(int l,int r)
{
	return query(r)-query(l-1);
}
signed main()
{
	freopen("count.in","r",stdin),freopen("count.out","w",stdout);
	read(n,S);
	ll ans=0;
	for(int i=1; i<=n; ++i)
	{
		int val;
		read(val);
		ans+=query(S-val+1,2e5);
		update(val,1);
	}
	printf("%lld\n",ans);
	return 0;
}


