#include<cstdio>
#define re register
using namespace std;
inline int read()
{
	char s=getchar();
	bool f=false;
	int x=0;
	while(!(s>='0'&&s<='9'))
	{
		if(s=='-')
			f=true;
		s=getchar();
	}
	while(s>='0'&&s<='9')
	{
		x=(x<<1)+(x<<3)+s-'0';
		s=getchar();
	}
	return f?-x:x;
}
inline long long read_ll()
{
	char s=getchar();
	bool f=false;
	long long x=0;
	while(!(s>='0'&&s<='9'))
	{
		if(s=='-')
			f=true;
		s=getchar();
	}
	while(s>='0'&&s<='9')
	{
		x=(x<<1)+(x<<3)+s-'0';
		s=getchar();
	}
	return f?-x:x;
}
const int N=1e5+5;
int n,m;
long long p,a[N];
struct node
{
	long long v,add,mul;
} sum[N<<2];
inline void build(int root,int l,int r)
{
	sum[root].mul=1;
	if(l==r)
		sum[root].v=a[l];
	else
	{
		int mid=l+r>>1;
		build(root<<1,l,mid);
		build(root<<1|1,mid+1,r);
		sum[root].v=sum[root<<1].v+sum[root<<1|1].v;
	}
	sum[root].v%=p;
	return;
}
inline void pushdown(int root,int l,int r,int mid)
{
	sum[root<<1].v=(sum[root<<1].v*sum[root].mul+(long long)(mid-l+1)*sum[root].add)%p;
	sum[root<<1|1].v=(sum[root<<1|1].v*sum[root].mul+(long long)(r-mid)*sum[root].add)%p;
	sum[root<<1].add=(sum[root<<1].add*sum[root].mul+sum[root].add)%p;
	sum[root<<1|1].add=(sum[root<<1|1].add*sum[root].mul+sum[root].add)%p;
	sum[root<<1].mul=(sum[root<<1].mul*sum[root].mul)%p;
	sum[root<<1|1].mul=(sum[root<<1|1].mul*sum[root].mul)%p;
	sum[root].add=0;
	sum[root].mul=1;
	return;
}
inline void update1(int root,int l,int r,int x,int y,long long v)
{
	if(l>y||r<x)
		return;
	if(l>=x&&r<=y)
	{
		sum[root].v=(sum[root].v*v)%p;
		sum[root].add=(sum[root].add*v)%p;
		sum[root].mul=(sum[root].mul*v)%p;
		return;
	}
	int mid=l+r>>1;
	pushdown(root,l,r,mid);
	update1(root<<1,l,mid,x,y,v);
	update1(root<<1|1,mid+1,r,x,y,v);
	sum[root].v=(sum[root<<1].v+sum[root<<1|1].v)%p;
	return;
}
inline void update2(int root,int l,int r,int x,int y,long long v)
{
	if(l>y||r<x)
		return;
	if(l>=x&&r<=y)
	{
		sum[root].v=(sum[root].v+(long long)(r-l+1)*v)%p;
		sum[root].add=(sum[root].add+v)%p;
		return;
	}
	int mid=l+r>>1;
	pushdown(root,l,r,mid);
	update2(root<<1,l,mid,x,y,v);
	update2(root<<1|1,mid+1,r,x,y,v);
	sum[root].v=(sum[root<<1].v+sum[root<<1|1].v)%p;
	return;
}
inline long long query(int root,int l,int r,int x,int y)
{
	if(l>y||r<x)
		return 0;
	if(l>=x&&r<=y)
		return sum[root].v;
	int mid=l+r>>1;
	pushdown(root,l,r,mid);
	return (query(root<<1,l,mid,x,y)+query(root<<1|1,mid+1,r,x,y))%p;
}
int main()
{
	n=read();
	p=read_ll();
	for(re int i=1; i<=n; i++)
		a[i]=read_ll();
	build(1,1,n);
	m=read();
	for(re int i=1,op,t,g; i<=m; i++)
	{

		op=read();
		t=read();
		g=read();
		if(op==1)
		{
			long long c=read_ll();
			update1(1,1,n,t,g,c);
		}
		else if(op==2)
		{
			long long c=read_ll();
			update2(1,1,n,t,g,c);
		}
		else
			printf("%lld\n",query(1,1,n,t,g));
	}
	return 0;
}
