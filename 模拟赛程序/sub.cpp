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
const int N=6005,K=1005,mod=1e9+7;
int f[N][N];
int a[N];
int start[K],last[K],QwQ[K];
inline void add(int &x,int y)
{
	x+=y;
	if(x>=mod)
		x-=mod;
}
inline void mul(int &x,int y)
{
	x-=y;
	if(x<0)
		x+=mod;
}
signed main()
{
	freopen("sub.in","r",stdin),freopen("sub.out","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		int n,m,k;
		read(n,m,k);
		for(int i=1; i<=n; ++i)
			read(a[i]);
		for(int l=n; l>=1; --l)
		{
			memset(start,0,sizeof(start));
			memset(last,0,sizeof(last));
			memset(QwQ,0,sizeof(QwQ));
			int nowans=0,cnt=0;
			for(int r=l; r<=n; ++r)
			{
				if(!start[a[r]])
				{
					start[a[r]]=r;
					++cnt;
				}
				last[a[r]]=r;
				if(start[a[r]]!=last[a[r]])
				{
					mul(nowans,QwQ[a[r]]);
					add(nowans,QwQ[a[r]]=f[start[a[r]]+1][last[a[r]]-1]+1);
//				if(l==1&&r==n)
//					printf("%d %d %d\n",start[a[r]]+1,last[a[r]]-1,f[2][4]);
				}
				f[l][r]=cnt;
				add(f[l][r],nowans);
			}
		}
//	for(int i=1; i<=n; ++i)
//	{
//		for(int j=1; j<=n; ++j)
//			printf(" %d",f[i][j]);
//		putchar('\n');
//	}
		for(int i=1; i<=m; ++i)
		{
			int l,r;
			read(l,r);
			printf("%d\n",f[l][r]);
		}
	}
	return 0;
}


