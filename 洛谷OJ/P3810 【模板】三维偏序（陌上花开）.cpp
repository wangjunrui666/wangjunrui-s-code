#include <cstdio>
#include <algorithm>
#define re register
using namespace std;

template <typename T>
inline void read(T &x)
{
	x=0;
	char s=(char)getchar();
	bool flag=false;
	while(s<'0'||s>'9')
	{
		if(s=='-')
			flag=true;
		s=(char)getchar();
	}
	while(s>='0'&&s<='9')
	{
		x=(x<<1)+(x<<3)+(s^'0');
		s=(char)getchar();
	}
	if(flag)
		x=~x+1;
	return;
}
const int N=1e5+5;
int sortflag;
struct Point
{
	int x[3];
	inline bool operator < (const Point &rhs)
	{
		return x[sortflag]<rhs.x[sortflag];
	}
} point[N],need;
struct Tree
{
	Point point;
	int l,r,size;
	int max[3],min[3];
} tree[N];
#define nextflag ((flag+1)%3)
#define lc(now) tree[now].l
#define rc(now) tree[now].r
int root,cnt;
inline int newnode(Point rhs)
{
	tree[++cnt].point=rhs;
	for(re int i=0; i<3; ++i)
		tree[cnt].max[i]=tree[cnt].min[i]=rhs.x[i];
	tree[cnt].size=1;
	return cnt;
}
inline void update(int rt)
{
	tree[rt].size=tree[lc(rt)].size+tree[rc(rt)].size+1;
	for(re int i=0; i<3; ++i)
	{
		tree[rt].max[i]=max(tree[rt].max[i],max(tree[lc(rt)].max[i],tree[rc(rt)].max[i]));
		tree[rt].min[i]=min(tree[rt].min[i],min(tree[lc(rt)].min[i],tree[rc(rt)].min[i]));
	}
}
inline void build(int &rt,int l,int r,int flag)
{
	int mid=(l+r)>>1;
	sortflag=flag;
	nth_element(point+l,point+mid,point+r+1);
	rt=newnode(point[mid]);
	if(l<mid)
		build(lc(rt),l,mid-1,nextflag);
	if(mid<r)
		build(rc(rt),mid+1,r,nextflag);
	update(rt);
}
inline int query(int rt)
{
	if(tree[rt].max[0]<=need.x[0]&&tree[rt].max[1]<=need.x[1]&&tree[rt].max[2]<=need.x[2])
		return tree[rt].size;
	if(!rt||tree[rt].min[0]>need.x[0]||tree[rt].min[1]>need.x[1]||tree[rt].min[2]>need.x[2])
		return 0ll;
	int res=0;
	if(tree[rt].point.x[0]<=need.x[0]&&tree[rt].point.x[1]<=need.x[1]&&tree[rt].point.x[2]<=need.x[2])
		res=1;
	return res+query(lc(rt))+query(rc(rt));
}
int n,k;
int map[N];
int main()
{
	for(re int i=0; i<3; ++i)
		tree[0].min[i]=-(tree[0].max[i]=-0x7fffffff);
	read(n),read(k);
	for(re int i=1; i<=n; ++i)
		for(re int j=0; j<3; ++j)
			read(point[i].x[j]);
	build(root,1,n,0);
	for(re int i=1; i<=n; ++i)
	{
		need=point[i];
		++map[query(root)];
	}
	for(re int i=1; i<=n; ++i)
		printf("%d\n",map[i]);
	return 0;
}
