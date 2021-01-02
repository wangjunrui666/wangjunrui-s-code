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
const int N=1e6+5;
int now=1;
int tot,prime[N],cnt[N];
struct Edge
{
	int u,v;
	Edge(int _u=0,int _v=0):u(_u),v(_v){}
} edge[N];
int num_edge;
inline void print(int n,int fa)
{
	while(!(n&1))
	{
		printf("%d %d\n",fa,++now);
		n>>=1;
	}
	if(n>1)
	{
		printf("%d %d\n",fa,++now);
		print(n-1,now);
	}
}
signed main()
{
//	freopen("b.in","r",stdin),freopen("b.out","w",stdout);
	int k;
	while(scanf("%d",&k)!=EOF)
	{
		now=1;
		print(k,1);
	}
	return 0;
}


