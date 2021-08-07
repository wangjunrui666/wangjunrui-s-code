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
const int N=3e5+5;
int n,m,fa[N];
inline int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
struct Tree
{
	int ch[2];
	int fa;
	int tag;
	int val,dist;
	inline void update(int add)
	{
		tag+=add;
		val+=add;
	}
} tree[N],valtree[N];
#define lc(x) tree[x].ch[0]
#define rc(x) tree[x].ch[1]
#define fa(x) tree[x].fa
int root[N];
inline void pushup(int x)
{
	tree[x].dist=tree[rc(x)].dist+1;
	if(lc(x))
		tree[lc(x)].fa=x;
	if(rc(x))
		tree[rc(x)].fa=x;
}
inline void pushdown(int x)
{
	if(tree[x].tag)
	{
		if(lc(x))
			tree[lc(x)].update(tree[x].tag);
		if(rc(x))
			tree[rc(x)].update(tree[x].tag);
		tree[x].tag=0;
	}
}
inline int merge(int x,int y)
{
	if(!x||!y)
		return x|y;
	if(tree[x].val<tree[y].val)
		swap(x,y);
	pushdown(x);
	rc(x)=merge(rc(x),y);
	if(tree[lc(x)].dist<tree[rc(x)].dist)
		swap(lc(x),rc(x));
	pushup(x);
}
int st[N];
inline void del(int x)
{
	int top;
	st[top=1]=x;
	for(int y=fa(x); y; y=fa(y))
		st[++top]=y;
	while(top)
		pushdown(st[top--]);
	int x=merge(lc(x),rc(x));
	while(fa(x))
	{
		x=fa(x);
		if(tree[lc(x)].dist<tree[rc(x)].dist)
			swap(lc(x),rc(x));
		if(tree[x].dist<=tree[rc(x)].dist+1)
			break;
		pushup(x);
	}
}
signed main()
{
	tree[0].dist=-1;
	read(n,m);
	for(int i=1; i<=n; ++i)
	{
		root[i]=fa[i]=i;
		read(tree[i].val);
	}
	for(int i=1; i<=m; ++i)
	{
		char opt[5];
		scanf("%s",opt);
		if(opt[0]=='U')
		{
			int x,y;
			read(x,y);
			x=find(x),y=find(y);
			if(x==y)
				continue;
			fa[y]=x;
			root[x]=merge(root[x],root[y]);
		}
		else if(opt[0]=='A')
		{
			if(opt[1]=='1')
			{
				int x,v;
				read(x,v);
				v-=alladd;
				del(x);
				tree[x].val=v;
				root[find(x)]=merge(root[find(x)],x);
			}
			else if(opt[1]=='2')
			{
				int x,v;
				read(x,v);
			}
			else if(opt[1]=='3')
			{
				int v;
				read(v);
				alladd+=v;
			}
		}
	}
	return 0;
}


