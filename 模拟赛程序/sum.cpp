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
const int N=1e6+5,mod=1e9+7;
inline void add(int &a,int b)
{
	a+=b;
	if(a>=mod)
		a-=mod;
}
inline int times(int a,int b)
{
	return (int)((ll)a*b%mod);
}
struct node
{
	int val,id;
	inline bool operator <(const node&rhs)const
	{
		return val<rhs.val;
	}
} a[N];
int n;
struct Tree_array
{
	int sum[N];
	inline void update(int pos,int val)
	{
		for(int i=pos; i<=n; i+=lowbit(i))
			add(sum[i],val);
	}
	inline int query(int pos)
	{
		int res=0;
		for(int i=pos; i; i-=lowbit(i))
			add(res,sum[i]);
		return res;
	}
	inline void clear()
	{
		memset(sum,0,sizeof(sum));
	}
} tree1,tree2;
signed main()
{
	freopen("sum.in","r",stdin),freopen("sum.out","w",stdout);
	read(n);
	for(int i=1; i<=n; ++i)
	{
		read(a[i].val);
		a[i].id=i;
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		const int &x=a[i].id;
		int res=0;
		add(res,times(n-x+1,tree1.query(x)));
		add(res,times(x,(tree2.query(n)-tree2.query(x)+mod)%mod));
		add(res,times(x,n-x+1));
		add(ans,times(res,a[i].val));
		tree1.update(x,x);
		tree2.update(x,n-x+1);
	}
	printf("%d\n",ans);
	return 0;
}


