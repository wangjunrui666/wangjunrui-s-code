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
int n,a[N],r[N],p[N],tot;
int g[N][2];
inline void dfs(int u)
{
	if(g[u][0])
		dfs(g[u][0]);
	r[++tot]=a[u];
	if(g[u][1])
		dfs(g[u][1]);
}
int maxx[N];
inline void update(int pos,int val)
{
	for(int i=pos; i<=n; i+=lowbit(i))
		maxx[i]=max(maxx[i],val);
}
inline int query(int pos)
{
	int res=0;
	for(int i=pos; i; i-=lowbit(i))
		res=max(res,maxx[i]);
	return res;
}
signed main()
{
	freopen("bst.in","r",stdin),freopen("bst.out","w",stdout);
	read(n);
	for(int i=1; i<=n; ++i)
		read(a[i]);
	for(int i=2; i<=n; ++i)
	{
		int fa,son;
		read(fa,son);
		g[fa][son]=i;
	}
	dfs(1);
	for(int i=1; i<=n; ++i)
		p[i]=(r[i]-=i);
	sort(p+1,p+1+n);
	tot=(int)(unique(p+1,p+1+n)-p-1);
	for(int i=1; i<=n; ++i)
	{
		r[i]=(int)(lower_bound(p+1,p+1+tot,r[i])-p);
		update(r[i],query(r[i])+1);
	}
	printf("%d\n",n-query(tot));
	return 0;
}


