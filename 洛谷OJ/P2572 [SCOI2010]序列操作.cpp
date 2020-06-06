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
inline void clear(T*a,int l,int r,int val)
{
	memset(&a[l],val,sizeof(T)*(r-l+1));
}
#define lc (rt<<1)
#define rc (rt<<1|1)
using std::swap;
using std::max;
const int N=1e5+5;
struct node
{
	int suf,pre,ans,size;
	int allsize;
	node():suf(0),pre(0),ans(0),size(0),allsize(0){}
	inline void update(int val)
	{
		suf=pre=ans=size=val;
	}
	inline friend node operator +(const node&rhsa,const node&rhsb)
	{
		node ans;
		ans.suf=(rhsb.suf==rhsb.allsize?rhsa.suf+rhsb.allsize:rhsb.suf);
		ans.pre=(rhsa.pre==rhsa.allsize?rhsa.allsize+rhsb.pre:rhsa.pre);
		ans.size=rhsa.size+rhsb.size;
		ans.allsize=rhsa.allsize+rhsb.allsize;
		ans.ans=max(max(rhsa.ans,rhsb.ans),rhsa.suf+rhsb.pre);
		return ans;
	}
};
struct Node
{
	node ans[2];
	Node()
	{
		ans[0]=node(),ans[1]=node();
	}
	Node(node a,node b)
	{
		ans[0]=a,ans[1]=b;
	}
	inline void reverse()
	{
		swap(ans[0],ans[1]);
	}
	inline Node operator +(const Node &rhs)const
	{
		return Node(ans[0]+rhs.ans[0],ans[1]+rhs.ans[1]);
	}
};
struct Tree
{
	int size;
	int tag;
	Node ans;
	bool rev;
	inline void update(int val)
	{
		tag=val;
		rev=false;
		ans.ans[val].update(size);
		ans.ans[val^1].update(0);
	}
	inline void reverse()
	{
		rev^=1;
		ans.reverse();
	}
} tree[N*4];
int a[N];
inline void pushup(int rt)
{
	tree[rt].ans=tree[lc].ans+tree[rc].ans;
}
inline void pushdown(int rt)
{
	if(tree[rt].tag!=-1)
	{
		tree[lc].update(tree[rt].tag);
		tree[rc].update(tree[rt].tag);
		tree[rt].tag=-1;
	}
	if(tree[rt].rev)
	{
		tree[lc].reverse();
		tree[rc].reverse();
		tree[rt].rev=false;
	}
}
inline void build(int rt,int l,int r)
{
	tree[rt].size=r-l+1;
	tree[rt].ans.ans[0].allsize=tree[rt].ans.ans[1].allsize=tree[rt].size;
//	printf("%d %d\n",tree[rt].ans.ans[0].allsize,tree[rt].ans.ans[1].allsize);
//	printf(" %d %d\n",l,r);
	if(l==r)
	{
		tree[rt].update(a[l]);
		return;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(rt);
}
inline void update(int rt,int l,int r,int x,int y,int val)
{
	if(r<x||l>y)
		return;
	if(x<=l&&r<=y)
	{
		tree[rt].update(val);
		return;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	update(lc,l,mid,x,y,val);
	update(rc,mid+1,r,x,y,val);
	pushup(rt);
}
inline void reverse(int rt,int l,int r,int x,int y)
{
	if(r<x||l>y)
		return;
	if(x<=l&&r<=y)
	{
		tree[rt].reverse();
		return;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	reverse(lc,l,mid,x,y);
	reverse(rc,mid+1,r,x,y);
	pushup(rt);
}
inline Node query(int rt,int l,int r,int x,int y)
{
	if(r<x||l>y)
		return Node();
	if(x<=l&&r<=y)
		return tree[rt].ans;
	pushdown(rt);
	int mid=(l+r)>>1;
	return query(lc,l,mid,x,y)+query(rc,mid+1,r,x,y);
}
#define Query 1,0,n-1
signed main()
{
	int n,m;
	read(n,m);
	for(re int i=0; i<n; ++i)
		read(a[i]);
	build(Query);
	while(m--)
	{
		int opt,l,r;
		read(opt,l,r);
		if(opt==0)
			update(Query,l,r,0);
		else if(opt==1)
			update(Query,l,r,1);
		else if(opt==2)
			reverse(Query,l,r);
		else printf("%d\n",opt==3?query(Query,l,r).ans[1].size:query(Query,l,r).ans[1].ans);
	}
	return 0;
}


