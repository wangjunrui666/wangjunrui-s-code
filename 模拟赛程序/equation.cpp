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
const int N=1e3+5,M=150*150*150+5,mod=1e6+9;
struct Edge
{
	int next,val,sum;
} edge[M];
int head[M],num_edge;
inline int query(int val)
{
	for(int i=head[(val%mod+mod)%mod]; i; i=edge[i].next)
	{
		if(edge[i].val==val)
			return edge[i].sum;
	}
	return 0;
}
inline void update(int val)
{
	assert((val%mod+mod)%mod>=0);
	for(int i=head[(val%mod+mod)%mod]; i; i=edge[i].next)
		if(edge[i].val==val)
		{
			++edge[i].sum;
			return;
		}
	edge[++num_edge].next=head[(val%mod+mod)%mod];
	edge[num_edge].val=val;
	edge[num_edge].sum=1;
	head[(val%mod+mod)%mod]=num_edge;
}
int n,m;
int a[N],p[N];
int tot;
int fac[N][N];
inline int quickpow(int aa,int power)
{
	int res=1;
	while(power)
	{
		if(power&1)
			res=res*aa;
		aa=aa*aa;
		power>>=1;
	}
	return res;
}
inline void dfs1(int pos,int sum=0)
{
	if(pos>n/2)
	{
//		printf("%d ",sum);
		update(sum);
		return;
	}
	for(int i=1; i<=m; ++i)
		dfs1(pos+1,sum+fac[i][pos]);
}
int ans;
inline void dfs2(int pos,int sum=0)
{
	if(pos>n)
	{
		ans+=query(-sum);
		return;
	}
	for(int i=1; i<=m; ++i)
		dfs2(pos+1,sum+fac[i][pos]);
}
signed main()
{
//	freopen("equation.in","r",stdin),freopen("equation.out","w",stdout);
	read(n,m);
	for(int i=1; i<=n; ++i)
		read(a[i],p[i]);
	clock_t begin=clock();
	for(int i=1; i<=m; ++i)
		for(int j=1; j<=n; ++j)
			fac[i][j]=a[j]*quickpow(i,p[j]);
	cerr<<clock()-begin<<endl;
	dfs1(1);
//	putchar('\n');
	dfs2(n/2+1);
	printf("%d\n",ans);
	return 0;
}
