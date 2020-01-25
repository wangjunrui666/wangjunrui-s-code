#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define re register
#define size sze
#define ll long long
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


const int N=3e5+5,LOGN=20;
struct Edge
{
	int next,to,dis;
	Edge() {}
	Edge(int x,int y):next(x),to(y) {}
} edge[N<<1];
int head[N],num_edge;
inline void add_edge(int from,int to)
{
	edge[++num_edge]=Edge(head[from],to);
	head[from]=num_edge;
}

vector<int>v[N];
inline void add(int from,int to)
{
	v[from].push_back(to);
	return;
}

int a[N],dfn[N],top[N],size[N],s[N],dep[N],fa[N],dfstime;
ll maxn[N];
inline void dfs1(int u,int fa_)
{
	fa[u]=fa_;
	size[u]=1;
	for(re int i=head[u]; i; i=edge[i].next)
	{
		int &v=edge[i].to,&w=edge[i].dis;
		if(v==fa_)
			continue;
		dep[v]=dep[u]+1;
		maxn[v]=min(maxn[u],w);
		dfs1(v,u);
		if(size[son[u]]<size[v])
			son[u]=v;
		size[u]+=size[v];
	}
}
inline void dfs2(int u,int topf)
{
	top[u]=topf;
	dfn[u]=++dfstime;
	if(!son[u])
		return;
	dfs2(son[u],top[u]);
	for(re int i=head[u]; i; i=edge[i].next)
	{
		int &v=edge[i].to,&w=edge[i].dis;
		if(top[v])
			continue;
		dfs2(v,v);
	}
}


