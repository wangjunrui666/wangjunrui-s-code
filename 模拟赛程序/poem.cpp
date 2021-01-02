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
const int N=45,maxS=1<<18,mod=1e9+7;
int g[maxS][15],f[N][maxS];
signed main()
{
	freopen("poem.in","r",stdin),freopen("poem.out","w",stdout);
	int n,x,y,z;
	read(n,x,y,z);
	y+=x,z+=y;
	for(int S=1; S<=(1<<z); ++S)
		for(int i=1; i<=10; ++i)
		{
			if(S==(1<<z))
				g[S][i]=(1<<z);
			else
			{
				g[S][i]=1;
				for(int j=0; j<z; ++j)
					if(((S>>j)&1)&&i+j<=z&&!(j<x&&i+j>x)&&!(j<y&&i+j>y))
						g[S][i]|=1<<(i+j);
				if(g[S][i]>=(1<<z))
					g[S][i]=(1<<z);
			}
		}
//	for(int S=1; S<=(1<<z); ++S)
//	{
//		printf("%d:",S);
//		for(int i=1; i<=10; ++i)
//			printf("%d ",g[S][i]);
//		putchar('\n');
//	}
	f[0][1]=1;
	for(int i=0; i<n; ++i)
		for(int S=1; S<=(1<<z); ++S)
			if(f[i][S])
				for(int j=1; j<=10; ++j)
					(f[i+1][g[S][j]]+=f[i][S])%=mod;
	printf("%d\n",f[n][1<<z]);
	return 0;
}


