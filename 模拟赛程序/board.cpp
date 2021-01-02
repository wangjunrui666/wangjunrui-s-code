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
int n,m,q;
int h[N],l[N];
bool hcol[N],lcol[N];
int tot;
struct Tree_array
{
	int c[N];
	inline void update(int pos,int val)
	{
		for(int i=pos; i<=tot; i+=lowbit(i))
			c[i]+=val;
	}
	inline int query(int pos)
	{
		int res=0;
		for(int i=pos; i; i-=lowbit(i))
			res+=c[i];
		return res;
	}
	inline int query(int x,int y)
	{
		return query(y)-query(x-1);
	}
} black,white;
signed main()
{
	freopen("board.in","r",stdin),freopen("board.out","w",stdout);
	read(n,m,q);
	bool flag=false;
	for(int i=1,pos=0; i<=q; ++i)
	{
		int x,y,z;
		read(x,y,z);
//		printf("%d %d %d\n",x,y,z);
		if(!x)
		{
			flag=true;
			pos=y;
		}
		else if(x==1)
		{
			flag=false;
			pos=y;
		}
		if(!z)
		{
			++tot;
			if(flag)
			{
				h[pos]=tot;
				hcol[pos]=false;
			}
			else
			{
				l[pos]=tot;
				lcol[pos]=false;
			}
		}
		else if(z==1)
		{
			++tot;
			if(flag)
			{
				h[pos]=tot;
				hcol[pos]=true;
			}
			else
			{
				l[pos]=tot;
				lcol[pos]=true;
			}
		}
	}
	for(int i=1; i<=n; ++i)
	{
		if(h[i])
		{
			if(hcol[i])
				black.update(h[i],1);
			else
				white.update(h[i],1);
		}
	}
//	for(int i=1; i<=n; ++i)
//		printf("%d %d\n",h[i],hcol[i]);
//	putchar('\n');
//	for(int i=1; i<=m; ++i)
//		printf("%d %d\n",l[i],lcol[i]);
	ll ans=0;
	for(int i=1; i<=m; ++i)
	{
		if(lcol[i])
			ans+=n-white.query(l[i]+1,tot);
		else
			ans+=black.query(l[i]+1,tot);
	}
	printf("%lld\n",ans);
	return 0;
}


