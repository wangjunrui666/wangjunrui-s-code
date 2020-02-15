#pragma GCC optimize(2)
#include<cstdio>
#define re register

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
using namespace std;
const int N=2e5+5e4+5;
struct Tree
{
	int l,r;
	int sum;
} tree[N*40];
#define lc(rt) tree[rt].l
#define rc(rt) tree[rt].r
int cnt,root[N];
inline void modify(int &rt,int l,int r,int pos,int val)
{
	if(!rt)
		rt=++cnt;
	tree[rt].sum+=val;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(pos<=mid)
		modify(lc(rt),l,mid,pos,val);
	else
		modify(rc(rt),mid+1,r,pos,val);
}
inline int query(int rt,int l,int r,int x,int y)
{
	if(!rt||r<x||l>y)
		return 0;
	if(x<=l&&r<=y)
		return tree[rt].sum;
	int mid=(l+r)>>1;
	return query(lc(rt),l,mid,x,y)+query(rc(rt),mid+1,r,x,y);
}
#define lowbit(x) (x&(-x))
int n,m,a[N];
inline void update(int rt,int pos,int val)
{
	for(re int i=rt; i<=n; i+=lowbit(i))
		modify(root[i],1,n,pos,val);
}
inline int query(int rootl,int rootr,int x,int y)
{
	int res=0;
	for(re int i=rootr; i; i-=lowbit(i))
		res+=query(root[i],1,n,x,y);
	for(re int i=rootl-1; i; i-=lowbit(i))
		res-=query(root[i],1,n,x,y);
	return res;
}
int c[N];
inline void update(int pos,int val)
{
	for(re int i=pos; i<=n; i+=lowbit(i))
		c[i]+=val;
}
inline int Query(int pos)
{
	int res=0;
	for(re int i=pos; i; i-=lowbit(i))
		res+=c[i];
	return res;
}
long long ans;
int pos[N];
int main()
{
	read(n),read(m);
	for(re int i=1; i<=n; ++i)
	{
		read(a[i]);
		pos[a[i]]=i;
		ans+=Query(n)-Query(a[i]);
		update(a[i],1);
		update(i,a[i],1);
	}
	for(re int i=1;i<=m;++i)
	{
		printf("%lld\n",ans);
		int x;
		read(x);
		ans-=query(1,pos[x]-1,x+1,n)+query(pos[x]+1,n,1,x-1);
		update(pos[x],x,-1);
	}
	return 0;
}
