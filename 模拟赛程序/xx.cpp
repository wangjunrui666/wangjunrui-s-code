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
const int N=25+5,mod=1e9+9,lim=25;
inline int times(int a,int b)
{
	return (int)((ll)a*b%mod);
}
inline int add(int a,int b)
{
	a+=b;
	if(a>=mod)
		a-=mod;
	return a;
}
inline int mul(int a,int b)
{
	a-=b;
	if(a<0)
		a+=mod;
	return a;
}
char opt[2];
int n,m;
int a[N],endval;
int fac[N];
int ans=0;
inline void dfs1(int pos,int len,int val)
{
	if(pos>n)
	{
		if(len&&val==endval)
			(ans+=fac[len])%=mod;
		return;
	}
	dfs1(pos+1,len,val);
	dfs1(pos+1,len+1,val&a[pos]);
}
inline void dfs2(int pos,int len,int val)
{
	if(pos>n)
	{
		if(len&&val==endval)
			(ans+=fac[len])%=mod;
		return;
	}
	dfs2(pos+1,len,val);
	dfs2(pos+1,len+1,val|a[pos]);
}

inline void dfs3(int pos,int len,int val)
{
	if(pos>n)
	{
		if(len&&val==endval)
			(ans+=fac[len])%=mod;
		return;
	}
	dfs3(pos+1,len,val);
	dfs3(pos+1,len+1,val^a[pos]);
}
signed main()
{
	freopen("xx.in","r",stdin),freopen("xx.out","w",stdout);
	scanf("%s",opt);
	read(n,m);
	for(int i=1; i<=n; ++i)
		for(int j=0; j<m; ++j)
		{
			int val;
			read(val);
			a[i]|=(val<<j);
		}
	for(int i=0; i<m; ++i)
	{
		int val;
		read(val);
		endval|=(val<<i);
	}
//	for(int i=1; i<=n; ++i)
//		printf("%d ",a[i]);
//	printf("\n%d\n",endval);
	fac[0]=1;
	for(int i=1; i<=25; ++i)
		fac[i]=(int)((ll)fac[i-1]*i%mod);
	if(opt[0]=='&')
		dfs1(1,0,(1<<m)-1);
	else if(opt[0]=='|')
		dfs2(1,0,0);
	else
		dfs3(1,0,0);
	printf("%d\n",ans);
	return 0;
}


