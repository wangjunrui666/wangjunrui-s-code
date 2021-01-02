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
int n,a[N],sum[N];
int q[N],head=1,tail;
signed main()
{
	freopen("genes.in","r",stdin),freopen("genes.out","w",stdout);
	read(n);
	for(int i=1; i<=n; ++i)
	{
		read(a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1; i<n; ++i)
		sum[i+n]=sum[i+n-1]+a[i];
	for(int i=1; i<n; ++i)
	{
		while(head<=tail&&sum[q[tail]]>sum[i])
			--tail;
		q[++tail]=i;
	}
	int ans=0;
	for(int i=n; i<2*n; ++i)
	{
		while(head<=tail&&q[head]<=i-n)
			++head;
		if(sum[q[head]]-sum[i-n]>=0)
			++ans;
		while(head<=tail&&sum[q[tail]]>sum[i])
			--tail;
		q[++tail]=i;
	}
	printf("%d\n",ans);
	return 0;
}


