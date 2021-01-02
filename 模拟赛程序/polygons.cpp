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
const int N=45;
struct Point
{
	int x,y;
	Point(int _x=0,int _y=0):x(_x),y(_y) {}
	inline Point operator +(const Point &rhs)const
	{
		return Point(x+rhs.x,y+rhs.y);
	}
	inline Point operator -(const Point &rhs)const
	{
		return Point(x-rhs.x,y-rhs.y);
	}
	inline int operator *(const Point &rhs)const
	{
		return x*rhs.y-y*rhs.x;
	}
	inline bool operator >(const Point &rhs)const
	{
		return x==rhs.x?y<rhs.y:x<rhs.x;
	}
	inline int norm()
	{
		return x*x+y*y;
	}
};
struct node
{
	Point point;
	double p;
	inline bool operator >(const node &rhs)const
	{
		return point>rhs.point;
	}
	inline Point operator -(const node &rhs)const
	{
		return point-rhs.point;
	}
	inline int norm()
	{
		return point.norm();
	}
} a[N];
int n;
signed main()
{
	freopen("polygons.in","r",stdin),freopen("polygons.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1; i<=n; ++i)
		cin>>a[i].point.x>>a[i].point.y>>a[i].p;
	for(int i=2; i<=n; ++i)
		if(a[i]>a[1])
			swap(a[1],a[i]);
	sort(a+2,a+1+n,[](node rhsx,node rhsy)
	{
		int ans=(rhsx-a[1])*(rhsy-a[1]);
		if(ans)
			return ans>0;
		else
			return (rhsx-a[1]).norm()<(rhsy-a[1]).norm();
	}
	    );
	double ans=0;
	for(int x=1; x<=n; ++x)
		for(int y=1; y<=n; ++y)
		{
			double now=a[x].p*a[y].p;
			for(int i=1; i<=n; ++i)
				if((a[i]-a[x])*(a[y]-a[x])>0)
					now*=(1-a[i].p);
			ans+=a[x].point*a[y].point*now;
		}
	printf("%.5lf\n",ans/2);
	return 0;
}


