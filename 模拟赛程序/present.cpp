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
const int N=1e6+5;
int n,m;
struct node
{
	int v,x;
	inline bool operator <(const node&rhs)const
	{
		return v>rhs.v;
	}
} a[N];
ll sum[N];
int cnt[N];
inline void work()
{
	ll w;
	read(w);
	int p=1;
	int summer=0;
	while(p<=n)
	{
		int l=p,r=n,ans=p-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(sum[mid]<=w)
			{
				ans=mid;
				l=mid+1;
			}
			else
				r=mid-1;
		}
		summer+=cnt[ans]-cnt[p-1];
		w-=sum[ans]-sum[p-1];
		if(ans<n)
		{
			ll add=w/a[ans+1].v;
			summer+=add;
			w-=add*a[ans+1].v;
		}
		l=ans+1,r=n,ans=n+1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(a[mid].v<=w)
			{
				ans=mid;
				r=mid-1;
			}
			else
				l=mid+1;
		}
		p=ans;
//		printf("%d\n",p);
	}
	printf("%d\n",summer);
}
int main()
{
	freopen("present.in","r",stdin),freopen("present.out","w",stdout);
	read(n,m);
	for(int i=1; i<=n; ++i)
		read(a[i].v,a[i].x);
	sort(a+1,a+1+n);
	for(int i=1; i<=n; ++i)
	{
		sum[i]=sum[i-1]+(ll)a[i].v*a[i].x;
		cnt[i]=cnt[i-1]+a[i].x;
	}
	for(int i=1; i<=m; ++i)
		work();
	return 0;
}


