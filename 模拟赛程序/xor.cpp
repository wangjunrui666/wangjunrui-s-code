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
#define size sze
int ch[N*31][2],tot=1,size[N*31];
inline void insert(int val)
{
	int u=1;
	for(int i=31; i>=0; --i)
	{
		int c=(val>>i)&1;
		if(!ch[u][c])
			ch[u][c]=++tot;
		u=ch[u][c];
//		printf("%d\n",u);
		++size[u];
	}
}
inline int find(int val,int k)
{
	int u=1,ans=0;
	for(int i=31; i>=0; --i)
	{
		int c=(val>>i)&1;
		if((k>>i)&1)
			u=ch[u][!c];
		else
		{
			ans+=size[ch[u][!c]];
//			printf("%d %d\n",ch[u][!c],size[ch[u][!c]]);
			u=ch[u][c];
		}
	}
//	printf("%d\n",size[u]);
//	printf("%d\n",ans+size[u]);
	return ans+size[u];
}
int sum[N];
inline void work()
{
	int n,k;
	read(n,k);
	for(int i=1; i<=n; ++i)
	{
		int val;
		read(val);
		sum[i]=sum[i-1]^val;
	}
	insert(sum[0]);
	ll ans=0;
	for(int i=1; i<=n; ++i)
	{
		ans+=find(sum[i],k);
//		printf("%d ",find(sum[i],k));
		insert(sum[i]);
	}
	memset(ch,0,sizeof(ch));
	memset(size,0,sizeof(size));
//	putchar('\n');
	printf("%lld\n",ans);
}
signed main()
{
	freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
	int T=1;
	read(T);
	while(T--)
		work();
	return 0;
}


