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
int n,m;
struct Queue
{
	int l,r,p;
} q[N];
int diff[N];
int ans[N];
inline void work(int pos)
{
	for(int i=1; i<=m; ++i)
		if((q[i].p>>pos)&1);
		else
		{
			++diff[q[i].l];
			--diff[q[i].r+1];
		}
	for(int i=1; i<=n; ++i)
		diff[i]+=diff[i-1];
	for(int i=1; i<=n; ++i)
	{
		diff[i]=min(diff[i],1);
		if(!diff[i])
			ans[i]|=(1<<pos);
	}
//	printf("%d:\n",pos);
//	for(int i=1; i<=n; ++i)
//		printf("%d ",diff[i]);
//	putchar('\n');
	for(int i=1; i<=n; ++i)
		diff[i]+=diff[i-1];
	for(int i=1; i<=m; ++i)
		if(((q[i].p>>pos)&1)&&diff[q[i].r]-diff[q[i].l-1]==q[i].r-q[i].l+1)
		{
			printf("No\n");
			exit(0);
		}
	clear(diff,1,n,0);
}
signed main()
{
	freopen("or.in","r",stdin),freopen("or.out","w",stdout);
	read(n,m);
	for(int i=1; i<=m; ++i)
		read(q[i].l,q[i].r,q[i].p);
	for(int i=0; i<=30; ++i)
		work(i);
	printf("Yes\n");
	for(int i=1; i<=n; ++i)
		printf("%d ",ans[i]);
	putchar('\n');
	return 0;
}


