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
int n,a[N];
int ch[N*31][2],tot;
ll ans=0;
inline void insert(int val)
{
	int u=1;
	for(int i=30; i>=0; --i)
	{
		int c=(val>>i)&1;
		if(!ch[u][c])
			ch[u][c]=++tot;
		u=ch[u][c];
	}
}
inline int find(int val)
{
	int u=1,res=0;
	for(int i=30; i>=0; --i)
	{
		int c=(val>>i)&1;
		if(ch[u][c])
			u=ch[u][c];
		else
		{
			res|=(1<<i);
			u=ch[u][!c];
		}
	}
	return res;
}
inline void dfs(int l,int r,int dep=30)
{
	if(l==r||dep==-1)
		return;
	int pos=l;
	while(!((a[pos]>>dep)&1)&&pos<=r)
		++pos;
//	printf("%d %d %d %d\n",dep,l,r,pos);
	if(l<pos&&pos<=r)
	{
		clear(ch,1,tot+1,0);
		tot=1;
		int minn=0x7fffffff;
		for(int i=l; i<pos; ++i)
			insert(a[i]);
		for(int i=pos; i<=r; ++i)
			minn=min(minn,find(a[i]));
		ans+=minn;
	}
	if(l<pos)
		dfs(l,pos-1,dep-1);
	if(pos<=r)
		dfs(pos,r,dep-1);
}
signed main()
{
	freopen("tree.in","r",stdin),freopen("tree.out","w",stdout);
	read(n);
	for(int i=1; i<=n; ++i)
		read(a[i]);
	sort(a+1,a+1+n);
	dfs(1,n);
	printf("%lld\n",ans);
	return 0;
}


