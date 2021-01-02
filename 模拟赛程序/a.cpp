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
const int N=1e7+5;
int T;
int a[N],len;
inline bool check(int n)
{
	int cnt1=0,cnt2=0;
	while(n)
	{
		if(n%3==1)
			++cnt1;
		if(n%3==2)
			++cnt2;
		n/=3;
	}
	return cnt1==cnt2;
}
inline void work()
{
	int n,m;
	read(n,m);
	for(int now=lower_bound(a+1,a+1+len,n)-a,i=1; i<=m; ++i,++now)
		printf("%d ",a[now]);
	putchar('\n');
	return;
}
signed main()
{
	freopen("a.in","r",stdin),freopen("a.out","w",stdout);
	for(int i=1; i<=1e7; ++i)
		if(check(i))
			a[++len]=i;
	read(T);
	while(T--)
		work();
	return 0;
}


