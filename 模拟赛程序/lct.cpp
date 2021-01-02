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
struct Tree
{
	int lc,rc,size;
} tree[N*80];
#define lc(x) tree[x].lc
#define rc(x) tree[x].rc
int root,cnt;
inline void update(int &rt,int l,int r,int pos,int val)
{
	if(!rt)
		rt=++cnt;
	tree[rt].size+=val;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(pos<=mid)
		update(lc(rt),l,mid,pos,val);
	else
		update(rc(rt),mid+1,r,pos,val);
}
inline int query(int rt,int l,int r,int k_th)
{
	if(l==r)
		return l;
	int mid=(l+r)>>1;
	if(tree[lc(rt)].size>=k_th)
		return query(lc(rt),l,mid,k_th);
	else
		return query(rc(rt),mid+1,r,k_th-tree[lc(rt)].size);
}
int n,k,type;
const int MAX=0x7fffffff;
signed main()
{
	freopen("lct.in","r",stdin),freopen("lct.out","w",stdout);
	read(n,k,type);
	int lastans=0;
	for(int i=1; i<=n; ++i)
	{
		int opt;
		read(opt);
		if(opt==1)
		{
			int x;
			read(x);
			if(type)
				x^=lastans;
			update(root,0,MAX,x,1);
		}
		else
		{
			printf("%d\n",lastans=query(root,0,MAX,tree[root].size-k+1));
			update(root,0,MAX,lastans,-1);
		}
	}
	return 0;
}


