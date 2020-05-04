#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define re register
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(re int i=a;i<=b;++i)
#define per(i,a,b) for(re int i=a;i>=b;--i)
using namespace std;
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
const int N=5e4+5;
int n,m,k,a[N];
int block,belong[N];
int cnt[N];
struct Queue
{
	int l,r,id;
	inline bool operator <(const Queue&rhs)const
	{
		if(belong[l]==belong[rhs.l])
			return r<rhs.r;
		return belong[l]<belong[rhs.l];
	}
} q[N];
ll ans;
inline void add(int pos)
{
	ans+=2*cnt[a[pos]]+1;
	++cnt[a[pos]];
}
inline void del(int pos)
{
	ans+=-2*cnt[a[pos]]+1;
	--cnt[a[pos]];
}
ll answer[N];
signed main()
{
	read(n,m,k);
	block=(int)sqrt(n);
	for(re int i=1; i<=n; ++i)
	{
		read(a[i]);
		belong[i]=(i-1)/block+1;
	}
	for(re int i=1; i<=m; ++i)
	{
		read(q[i].l,q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+1+m);
	int l=1,r=0;
	for(re int i=1; i<=m; ++i)
	{
		const int &ql=q[i].l,&qr=q[i].r;
//		printf("%d %d\n",ql,qr);
		while(ql<l)
			add(--l);
		while(ql>l)
			del(l++);
		while(qr<r)
			del(r--);
		while(qr>r)
			add(++r);
		answer[q[i].id]=ans;
	}
	for(re int i=1; i<=m; ++i)
		printf("%lld\n",answer[i]);
	return 0;
}

