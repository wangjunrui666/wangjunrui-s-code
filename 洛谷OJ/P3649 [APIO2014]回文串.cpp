#include <cstdio>
#include <algorithm>
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
const int N=3e5+5,M=N<<1;
struct Tree
{
	int fa,len,ch[26];
} point[M];
int tot=1,las=1;
int f[M];
inline void insert(int c)
{
	int p=las;
	int np=las=++tot;
	point[np].len=point[p].len+1;
	f[np]=1;
	for(; p&&!point[p].ch[c]; p=point[p].fa)
		point[p].ch[c]=np;
	if(!p)
		point[np].fa=1;
	else
	{
		int q=point[p].ch[c];
		if(point[p].len+1==point[q].len)
			point[np].fa=q;
		else
		{
			int nq=++tot;
			point[nq]=point[q];
			point[nq].len=point[p].len+1;
			point[np].fa=point[q].fa=nq;
			for(; p&&point[p].ch[c]==q; p=point[p].fa)
				point[p].ch[c]=nq;
		}
	}
}
struct Edge
{
	int next,to;
} edge[M];
ll ans;
int head[M],num_edge;
inline void add_edge(int from,int to)
{
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	head[from]=num_edge;
}
inline void dfs(int u)
{
	for(re int i=head[u]; i; i=edge[i].next)
	{
		int &v=edge[i].to;
		dfs(v);
		f[u]+=f[v];
	}
//	printf("%d %d %d %d %d\n",u,f[u],len(u),fa(u),pre);
	ans=max(ans,1ll*f[u]*point[u].len);
}
char str[N];
signed main()
{
	scanf("%s",str);
	for(re int i=0; str[i]; ++i)
		insert(str[i]-'a');
	for(re int i=2; i<=tot; ++i)
		add_edge(point[i].fa,i);
	dfs(1);
//	for(re int i=1; i<=tot; ++i)
//		printf("%d ",f[i]);
	printf("%lld\n",ans);
	return 0;
}

