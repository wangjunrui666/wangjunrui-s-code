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
struct Tree
{
	int val,max;
	ll sum;
} tree[N*4];
#define lc (rt<<1)
#define rc (rt<<1|1)
inline void pushup(int rt)
{
	tree[rt].sum=tree[lc].sum+tree[rc].sum;
	tree[rt].max=max(tree[lc].max,tree[rc].max);
}
inline void update(int rt,int l,int r,int x,int y,int mod)
{
	if(l>y||r<x)
		return;
	if(tree[rt].max<mod)
		return;
	if(l==r)
	{
		tree[rt].val%=mod;
		tree[rt].sum=tree[rt].max=tree[rt].val;
		return;
	}
	int mid=(l+r)>>1;
	update(lc,l,mid,x,y,mod);
	update(rc,mid+1,r,x,y,mod);
	pushup(rt);
}
inline void update(int rt,int l,int r,int pos,int val)
{
	if(l==r)
	{
		tree[rt].sum=tree[rt].max=tree[rt].val=val;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)
		update(lc,l,mid,pos,val);
	else
		update(rc,mid+1,r,pos,val);
	pushup(rt);
}
struct Edge
{
	int next,to;
} edge[N<<1];
int head[N],num_edge;
inline void add_edge(int from,int to)
{
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	head[from]=num_edge;
}
#define size sze
int n,m;
int dep[N],size[N],top[N],son[N],dfn[N],fa[N],dfstime;
inline void dfs1(int u,int _fa)
{
	dep[u]=dep[_fa]+1;
	size[u]=1;
	fa[u]=_fa;
	for(int i=head[u]; i; i=edge[i].next)
	{
		int &v=edge[i].to;
		if(v==_fa)
			continue;
		dfs1(v,u);
		sze[u]+=sze[v];
		if(sze[v]>sze[son[u]])
			son[u]=v;
	}
}
inline void dfs2(int u,int topf)
{
	dfn[u]=++dfstime;
	top[u]=topf;
	if(son[u])
		dfs2(son[u],topf);
	for(int i=head[u]; i; i=edge[i].next)
	{
		int &v=edge[i].to;
		if(top[v])
			continue;
		dfs2(v,v);
	}
}
inline ll query(int rt,int l,int r,int x,int y)
{
	if(l>y||r<x)
		return 0;
//	printf("%d %d\n",l,r);
	if(x<=l&&r<=y)
		return tree[rt].sum;
	int mid=(l+r)>>1;
	return query(lc,l,mid,x,y)+query(rc,mid+1,r,x,y);
}
inline ll query(int x,int y)
{
	ll sum=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		sum+=query(1,1,n,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])
		swap(x,y);
	sum+=query(1,1,n,dfn[x],dfn[y]);
	return sum;
}
signed main()
{
	freopen("flower.in","r",stdin),freopen("flower.out","w",stdout);
	read(n,m);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		read(u,v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1; i<=n; ++i)
	{
		int val;
		read(val);
		update(1,1,n,dfn[i],val);
	}
	for(int i=1; i<=m; ++i)
	{
		int opt,u,v;
		read(opt,u,v);
		if(opt==1)
			update(1,1,n,dfn[u],dfn[u]+size[u]-1,v);
		else if(opt==2)
			update(1,1,n,dfn[u],v);
		else if(opt==3)
			printf("%lld\n",query(u,v));
	}
	return 0;
}


