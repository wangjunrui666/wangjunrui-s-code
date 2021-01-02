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
const int N=5005;
int a[N],b[N];
int f[N][N],g[N][N];
inline void print(int pos,int x,int y)
{
	if(!pos)
		return;
	while(a[x]!=b[y])
		--x;
	print(pos-1,x,g[x][y]);
	printf("%d ",b[y]);
}
int n,m;
signed main()
{
	freopen("okarin.in","r",stdin),freopen("okarin.out","w",stdout);
	read(n);
	for(int i=1; i<=n; ++i)
		read(a[i]);
	read(m);
	for(int i=1; i<=m; ++i)
		read(b[i]);
	for(int i=1; i<=n; ++i)
		for(int pre=0,j=1; j<=m; ++j)
		{
			if(b[j]<a[i]&&f[i-1][j]>f[i-1][pre])
				pre=j;
			if(a[i]==b[j])
			{
				f[i][j]=f[i-1][pre]+1;
				g[i][j]=pre;
			}
			else
				f[i][j]=f[i-1][j];
		}
	int ans=0,id=0;
	for(int i=1; i<=m; ++i)
		if(f[n][i]>ans)
			ans=f[n][id=i];
	printf("%d\n",ans);
	if(ans)
		print(ans,n,id);
	return 0;
}


