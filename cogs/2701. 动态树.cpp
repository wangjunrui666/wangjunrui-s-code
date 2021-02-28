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
const int N=1e6+5;
struct Tree
{
	int ch[2];
	int fa;
	int size,fakesize;
	bool rev;
} tree[N];
#define lc(x) tree[x].ch[0]
#define rc(x) tree[x].ch[1]
#define fa(x) tree[x].fa
#define rev(x) tree[x].rev
inline bool nroot(int x)
{
	return lc(fa(x))==x||rc(fa(x))==x;
}
inline bool check(int x)
{
	return rc(fa(x))==x;
}
inline void pushup(int x)
{
	tree[x].size=tree[lc(x)].size+tree[rc(x)].size+tree[x].fakesize+1;
}
inline void pushdown(int x)
{
	if(rev(x))
	{
		if(lc(x))
			rev(lc(x))^=1;
		if(rc(x))
			rev(rc(x))^=1;
		swap(lc(x),rc(x));
		rev(x)=false;
	}
}
inline void rotate(int x)
{
	int y=fa(x),z=fa(y),k=check(x),w=tree[x].ch[k^1];
	if(nroot(y))
		tree[z].ch[check(y)]=x;
	tree[y].ch[k]=w;
	tree[x].ch[k^1]=y;
	if(w)
		fa(w)=y;
	fa(y)=x;
	fa(x)=z;
	pushup(z),pushup(y),pushup(x);
}
int st[N];
inline void splay(int x)
{
	int top;
	st[top=1]=x;
	for(re int y=x; nroot(y); y=fa(y))
		st[++top]=fa(y);
	while(top)
		pushdown(st[top--]);
	while(nroot(x))
	{
		if(nroot(fa(x)))
			rotate(check(x)==check(fa(x))?fa(x):x);
		rotate(x);
	}
}
inline void access(int x)
{
	for(int y=0; x; x=fa(y=x))
	{
		splay(x);
		tree[x].fakesize+=tree[rc(x)].size; 
		rc(x)=y;
		tree[x].fakesize-=tree[rc(x)].size;
		pushup(x);
	}
}
inline void makeroot(int x)
{
	access(x);
	splay(x);
	rev(x)^=1;
}
inline int findroot(int x)
{
	access(x);
	splay(x);
	while(pushdown(x),lc(x))
		x=lc(x);
	splay(x);
	return x;
}
inline void link(int x,int y)
{
	makeroot(x);
	access(y);
	splay(y);
	fa(x)=y;
	tree[y].fakesize+=tree[x].size;
	pushup(y);
}
int n,m;
signed main()
{
	freopen("dynamic_tree.in","r",stdin);
	freopen("dynamic_tree.out","w",stdout);
	read(n,m);
//	for(int i=1; i<=n; ++i)
//		tree[i].size=1;
	while(m--)
	{
		int opt;
		read(opt);
		if(opt==1)
		{
			int u;
			read(u);
			makeroot(u);
		}
		else if(opt==2)
		{
			int u;
			read(u);
			access(u);
			printf("%d\n",tree[u].fakesize+1);
		}
		else
		{
			int u,v;
			read(u,v);
			int rt=findroot(u);
			link(u,v);
			makeroot(rt);
		}
	}
	return 0;
}


