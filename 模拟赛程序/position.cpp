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
const int N=2e5+5;
int n,q;
struct Tree_array
{
	ll c[N];
	inline void update(int pos,ll val)
	{
		for(int i=pos; i<=n; i+=lowbit(i))
			c[i]+=val;
	}
	inline ll query(int pos)
	{
		ll res=0;
		for(int i=pos; i; i-=lowbit(i))
			res+=c[i];
		return res;
	}
	inline ll query(int l,int r)
	{
		return query(r)-query(l-1);
	}
} a,b;
inline ll calc(int pos)
{
	return pos*a.query(pos-1)-b.query(pos-1)+b.query(pos+1,n)-pos*a.query(pos+1,n);
}
#define lc (rt<<1)
#define rc (rt<<1|1)
class Segment1
{
	public:

		struct Tree
		{
			ll size;
		} tree[N<<2];
		inline void update(int rt,int l,int r,int pos,int val)
		{
			tree[rt].size+=val;
			if(l==r)
				return;
			int mid=(l+r)>>1;
			if(pos<=mid)
				update(lc,l,mid,pos,val);
			else
				update(rc,mid+1,r,pos,val);
		}
		inline int query(int rt,int l,int r,ll rk)
		{
			if(l==r)
				return l;
			ll cnt=tree[lc].size;
			int mid=(l+r)>>1;
			if(rk<=cnt)
				return query(lc,l,mid,rk);
			else
				return query(rc,mid+1,r,rk-cnt);
		}
} tree1;
const int INF=0x3f3f3f3f;
class Segment2
{
	public:
		struct Tree
		{
			int tag;
			int min,max;
			inline void update(int l,int r,int val)
			{
				if(val)
				{
					tag=1;
					min=l,max=r;
				}
				else
				{
					tag=0;
					min=INF,max=-INF;
				}
			}
		} tree[N<<2];
		inline void pushdown(int rt,int l,int r,int mid)
		{
			if(tree[rt].tag!=-1)
			{
				tree[lc].update(l,mid,tree[rt].tag);
				tree[rc].update(mid+1,r,tree[rt].tag);
				tree[rt].tag=-1;
			}
		}
		inline void pushup(int rt)
		{
			tree[rt].max=max(tree[lc].max,tree[rc].max);
			tree[rt].min=min(tree[lc].min,tree[rc].min);
		}
		inline void update(int rt,int l,int r,int x,int y,int val)
		{
			if(x<=l&&r<=y)
			{
				tree[rt].update(l,r,val);
				return;
			}
			if(r<x||l>y)
				return;
			int mid=(l+r)>>1;
			pushdown(rt,l,r,mid);
			update(lc,l,mid,x,y,val);
			update(rc,mid+1,r,x,y,val);
			pushup(rt);
		}
		inline int querymin(int rt,int l,int r,int x,int y)
		{
			if(x<=l&&r<=y)
				return tree[rt].min;
			if(r<x||l>y)
				return INF;
			int mid=(l+r)>>1;
			pushdown(rt,l,r,mid);
			return min(querymin(lc,l,mid,x,y),querymin(rc,mid+1,r,x,y));
		}
		inline int querymax(int rt,int l,int r,int x,int y)
		{
			if(x<=l&&r<=y)
				return tree[rt].max;
			if(r<x||l>y)
				return -INF;
			int mid=(l+r)>>1;
			pushdown(rt,l,r,mid);
			return max(querymax(lc,l,mid,x,y),querymax(rc,mid+1,r,x,y));
		}
} tree2;
signed main()
{
	 freopen("position.in","r",stdin),freopen("position.out","w",stdout);
	read(n,q);
	ll sum=0;
	tree2.update(1,1,n,1,n,1);
//	for(int i=1; i<=n; ++i)
//		printf("%d %d\n",tree2.querymin(1,1,n,i,n),tree2.querymax(1,1,n,1,i));
	for(int i=1; i<=n; ++i)
	{
		int val;
		read(val);
		sum+=val;
		tree1.update(1,1,n,i,val);
		a.update(i,val);
		b.update(i,(ll)val*i);
	}
	while(q--)
	{
		int opt,x,y;
		read(opt,x,y);
		if(opt==1)
		{
			tree1.update(1,1,n,x,y);
			a.update(x,y);
			b.update(x,(ll)x*y);
			sum+=y;
		}
		else if(opt==2)
		{
			tree1.update(1,1,n,x,-y);
			a.update(x,-y);
			b.update(x,-(ll)x*y);
			sum-=y;
		}
		else if(opt==3)
			tree2.update(1,1,n,x,y,1);
		else if(opt==4)
			tree2.update(1,1,n,x,y,0);
		int ans=tree1.query(1,1,n,(sum+1)>>1);
		if(tree2.querymax(1,1,n,ans,ans)!=-INF)
			printf("%d\n",ans);
		else
		{
			int ans1=tree2.querymax(1,1,n,1,ans-1),ans2=tree2.querymin(1,1,n,ans+1,n);
			if(ans1==-INF&&ans2==INF)
				printf("-1\n");
			else if(ans1<=-INF)
				printf("%d\n",ans2);
			else if(ans2>=INF)
				printf("%d\n",ans1);
			else if(calc(ans1)<=calc(ans2))
				printf("%d\n",ans1);
			else
				printf("%d\n",ans2);
		}
	}
	return 0;
}


