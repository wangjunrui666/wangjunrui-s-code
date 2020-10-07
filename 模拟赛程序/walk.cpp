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
const int N=20;
struct Matrix
{
	double g[N*N][N*N];
	int n,m;
	Matrix(int _n=0,int _m=0):n(_n),m(_m)
	{
		memset(g,0,sizeof(g));
	}
	inline Matrix operator *(const Matrix &rhs)const
	{
		Matrix ans=Matrix(n,rhs.m);
		for(int i=1; i<=ans.n; ++i)
			for(int j=1; j<=ans.m; ++j)
				for(int k=1; k<=m; ++k)
					ans.g[i][j]+=g[i][k]*rhs.g[k][j];
		return ans;
	}
	inline Matrix operator ^(int power)const
	{
		Matrix ans=Matrix(this->n,this->n),a=(*this);
		for(int i=1; i<=n; ++i)
			ans.g[i][i]=1;
		while(power)
		{
			if(power&1)
				ans=ans*a;
			a=a*a;
			power>>=1;
		}
		return ans;
	}
} base;
double p[N][N];
int n,m,d,a[N];
inline int calc(int x,int y)
{
	return (x-1)*n+y;
}
signed main()
{
	freopen("walk.in","r",stdin),freopen("walk.out","w",stdout);
	read(n,m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			scanf("%lf",&p[i][j]);
	read(d);
	for(int i=1; i<=n; ++i)
		read(a[i]);
	base=Matrix(n*n,n*n);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
				for(int x=1; x<=n; ++x)
					for(int y=1; y<=n; ++y)
						if(a[x]==a[y])
							base.g[calc(i,j)][calc(x,y)]=p[i][x]*p[j][y];
	Matrix res=base^(m-1);
	double ans=0;
//	for(int i=1; i<=n; ++i)
//		for(int j=1; j<=n; ++j)
//			for(int x=1; x<=n; ++x)
//				for(int y=1; y<=n; ++y)
//					printf("(%d,%d)->(%d,%d)=%lf\n",i,j,x,y,res.g[calc(i,j)][calc(x,y)]);
	for(int i=1; i<=n*n; ++i)
			ans+=res.g[1][i];
	printf("%.8lf\n",ans);
	return 0;
}


