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
const int N=1e6+5,M=1e5+5;
int n,m;
struct Queue
{
	int u,v,w;
	inline bool operator <(const Queue&rhs)const
	{
		return w>rhs.w;
	}
} q[N];
struct Tree_Array
{
	int c[M];
	inline void update(int pos,int val)
	{
		pos=max(pos,1);
		for(int i=pos; i<=n; i+=lowbit(i))
			c[i]+=val;
	}
	inline int query(int pos)
	{
		int res=0;
		for(int i=pos; i; i-=lowbit(i))
			res+=c[i];
		return res;
	}
	inline void clear()
	{
		memset(c,0,sizeof(c));
	}
} tree1,tree2;
inline bool check(int val)
{
//	printf("   %d\n",val);
	int cnt=0;
	for(int i=1; i<=m&&q[i].w>val; ++i)
	{
		tree1.update(q[i].u-val,1);
		tree1.update(q[i].u+val+1,-1);
		++cnt;
	}
	for(int x=1; x<=n; ++x)
		if(tree1.query(x)==cnt)
		{
//			printf("%d:\n",x);
			for(int i=1; i<=cnt; ++i)
			{
//				printf(" %d %d\n",q[i].v-(val-abs(q[i].u-x)),q[i].v+(val-abs(q[i].u-x)));
				tree2.update(q[i].v-(val-abs(q[i].u-x)),1);
				tree2.update(q[i].v+(val-abs(q[i].u-x))+1,-1);
			}
			for(int y=x+1; y<=n; ++y)
			{
//				printf("%d %d\n",y,tree2.query(y));
				if(tree2.query(y)==cnt)
				{
					tree2.clear();
					return true;
				}
			}
			tree2.clear();
		}
//	putchar('\n');
	tree1.clear();
	return false;
}
signed main()
{
	freopen("wormhole.in","r",stdin),freopen("wormhole.out","w",stdout); 
	read(n,m);
	for(int i=1; i<=m; ++i)
	{
		read(q[i].u,q[i].v);
		if(q[i].u>q[i].v)
			swap(q[i].u,q[i].v);
		q[i].w=q[i].v-q[i].u;
	}
	sort(q+1,q+1+m);
	int l=0,r=q[1].w,ans=q[1].w;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}


