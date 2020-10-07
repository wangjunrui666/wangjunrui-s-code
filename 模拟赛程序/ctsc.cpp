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
const int N=55;
ll C[N][N];
inline ll f(int n,int m)
{
	if(n<0||m<0||m>n)
		return 0;
	return C[n][m];
}
int m,n,s,t,a[N];
struct node
{
	int max,min,p;
	inline bool operator <(const node &rhs)const
	{
		return max==rhs.max?min>rhs.min:max>rhs.max;
	}
} e[N];
char str[N];
signed main()
{
	freopen("ctsc.in","r",stdin),freopen("ctsc.out","w",stdout);
	read(m);
	for(int i=1; i<=m; ++i)
		read(a[i]);
	read(n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s",str+1);
		for(int j=1; j<=m; ++j)
		{
			if(str[j]=='Y')
			{
				if(a[j]>=0)
					e[i].min+=a[j];
				e[i].max+=abs(a[j]);
			}
		}
	}
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			if(e[i].max<e[j].min||(e[i].max==e[j].min&&j<i))
				++e[i].p;
//	for(int i=1; i<=n; ++i)
//	{
//		printf("%d %d\n",i,e[i].p);
//	}
	sort(e+1,e+1+n);
	C[0][0]=1;
	for(int i=1; i<=50; ++i)
	{
		C[i][0]=1;
		for(int j=1; j<=i; ++j)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
//	for(int i=0; i<=50; ++i)
//	{
//		for(int j=0; j<=i; ++j)
//			printf("%lld ",C[i][j]);
//		putchar('\n');
//	}
	read(s,t);
	ll ans=0;
	for(int i=t; i<=n; ++i)
		if(e[i].p+1<=s)
		{
			for(int j=0; j<=min(e[i].p,t-1); ++j)
			{
				if(t-j>s-e[i].p)
					continue;
				ans+=f(e[i].p,j)*f(i-1-e[i].p,t-j-1);
//				printf("%d %d\n",e[i].p,j);
			}
//			printf("%d\n",ans);
		}
	printf("%lld\n",ans);
	return 0;
}


