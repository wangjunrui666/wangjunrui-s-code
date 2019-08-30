#include<cstdio>
#include<algorithm>
#define re register
#define lson (rt<<1)
#define rson (rt<<1|1)
#define ll long long
using namespace std;
template<typename T>
inline void read(T&x)
{
	x=0;
	char s=getchar();
	bool f=false;
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
	if(f)
		x=(~x)+1;
	return;
}
const int MAXN=1e6+10;
int n,cnt=0;
ll x1,y1,x2,y2,x[MAXN<<1];
struct Line
{
	ll l,r,h;
	int mark;
	inline bool operator < (const Line &a) const
	{
		return h<a.h;
	}
}line[MAXN<<1];
struct Tree
{
	int l,r,sum;
	ll len;
} tree[MAXN<<2];
inline void build(int rt,int l,int r)
{
	tree[rt].l=l;
	tree[rt].r=r;
	tree[rt].len=tree[rt].sum=0;
	if(l==r)
		return;
	int mid=l+r>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	return;
}
inline void pushup(int rt)
{
	const int &l=tree[rt].l,&r=tree[rt].r;
	if(tree[rt].sum)
		tree[rt].len=x[r+1]-x[l];
	else
		tree[rt].len=tree[lson].len+tree[rson].len;
	return;
}
inline void edit_tree(int rt,ll L,ll R,int c)
{
	const int &l=tree[rt].l,&r=tree[rt].r;
	if(x[r+1]<=L||R<=x[l])
		return;
	if(L<=x[l]&&x[r+1]<=R)
	{
		tree[rt].sum+=c;
		pushup(rt);
		return;
	}
	edit_tree(lson,L,R,c);
	edit_tree(rson,L,R,c);
	pushup(rt);
	return;
}
int main()
{
	read(n);
	for(re int i=1; i<=n; i++)
	{
		read(x1);
		read(y1);
		read(x2);
		read(y2);
		x[(i<<1)-1]=x1;
		x[i<<1]=x2;
		line[(i<<1)-1]=(Line)
		{
			x1,x2,y1,1
		};
		line[i<<1]=(Line)
		{
			x1,x2,y2,-1
		};
	}
	n<<=1;
	sort(line+1,line+n+1);
	sort(x+1,x+n+1);;
	int tot=unique(x+1,x+n+1)-x-1;
	build(1,1,tot-1);
	ll ans=0;
	for(re int i=1; i<n; i++)
	{
		edit_tree(1,line[i].l,line[i].r,line[i].mark);
		ans+=tree[1].len*(line[i+1].h-line[i].h);
	}
	printf("%lld\n",ans);
	return 0;
}

