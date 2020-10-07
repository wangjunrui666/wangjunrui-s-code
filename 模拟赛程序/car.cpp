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
const int N=1e5+5;
int tim;
struct node
{
	int v,s,pos;
	inline bool operator <(const node &rhs)const
	{
		return s+(ll)tim*v==rhs.s+(ll)tim*rhs.v?pos<rhs.pos:s+(ll)tim*v>rhs.s+(ll)tim*rhs.v;
	}
} a[N];
int n,m;
inline void update()
{
	for(int i=1; i<=n; ++i)
	{
		int now=i;
		while(now>1&&a[now]<a[now-1])
		{
			swap(a[now-1],a[now]);
			--now;
		}
	}
}
struct Queue
{
	int t,k,pos;
	inline bool operator <(const Queue&rhs)const
	{
		return t<rhs.t;
	}
} q[N];
int ans[N];
signed main()
{
	freopen("car.in","r",stdin),freopen("car.out","w",stdout);
	read(n);
	for(int i=1; i<=n; ++i)
	{
		read(a[i].v,a[i].s);
		a[i].pos=i;
	}
	read(m);
	for(int i=1; i<=m; ++i)
	{
		read(q[i].t,q[i].k);
		q[i].pos=i;
	}
	sort(q+1,q+1+m);
	tim=q[1].t;
	sort(a+1,a+1+n);
	ans[q[1].pos]=a[q[1].k].pos;
	for(int i=2; i<=m; ++i)
	{
		if(q[i].t>tim)
		{
			tim=q[i].t;
			update();
		}
//		for(int j=1; j<=n; ++j)
//			printf("%d ",a[j].pos);
//		putchar('\n');
		ans[q[i].pos]=a[q[i].k].pos;
	}
	for(int i=1; i<=m; ++i)
		printf("%d\n",ans[i]);
	return 0;
}

