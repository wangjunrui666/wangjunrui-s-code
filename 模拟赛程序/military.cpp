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
const int N=2e6+5;
int m[N],c[N];
int n;
int tot;
struct node
{
	int val,id;
	node(int _val=0,int _id=0):val(_val),id(_id) {}
	inline bool operator <(const node &rhs)const
	{
		return val<rhs.val;
	}
} p[N];
int now[N];
int h[N];
signed main()
{
	freopen("military.in","r",stdin),freopen("military.out","w",stdout);
	read(n);
	int sum=0;
	for(int i=1; i<=n; ++i)
	{
		read(m[i],c[i]);
		c[i]+=m[i-1];
		for(int j=1; j<=m[i]; ++j)
		{
			int val;
			read(val);
			p[++tot]=node(val,i);
			h[tot]=val;
		}
		m[i]+=m[i-1];
		sort(h+m[i-1]+1,h+m[i]+1);
	}
	sort(p+1,p+1+tot);
	int maxx=0;
	for(int i=1; i<=n; ++i)
		maxx=max(maxx,h[c[i]]);
	int ans=1e9;
	for(int i=1; i<=tot; ++i)
	{
		ans=min(ans,maxx-p[i].val);
		++c[p[i].id];
//		printf("min=%d max=%d %d %d\n",p[i].val,maxx,p[i].id,c[p[i].id]);
		if(c[p[i].id]>m[p[i].id])
			break;
		maxx=max(maxx,h[c[p[i].id]]);
	}
	printf("%d\n",ans);
	return 0;
}


