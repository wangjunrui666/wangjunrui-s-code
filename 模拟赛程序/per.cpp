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
const int N=1e5+5;
int n,a[N],ans[N],pos[N],id[N],nxt[N],pre[N];
int heap[N],heap_size;
int mp[N];
bitset<N>vis;
signed main()
{
	freopen("per.in","r",stdin),freopen("per.out","w",stdout);
	read(n);
	for(int i=1; i<=n; ++i)
	{
		read(a[i]);
		mp[a[i]]=i;
		nxt[i]=i+1;
		pre[i]=i-1;
	}
	int tot=0;
//	for(int j=1; j<=n; ++j)
//		printf("%d ",mp[j]);
//	putchar('\n');
	for(int i=n; i>=1; --i)
		if(a[mp[i]]&&a[nxt[mp[i]]])
		{
//			printf("%d %d\n",i,a[mp[i]+1]);
			ans[++tot]=a[mp[i]];
			ans[++tot]=a[nxt[mp[i]]];
			a[mp[i]]=0;
			a[nxt[mp[i]]]=0;
			pre[nxt[nxt[mp[i]]]]=pre[mp[i]];
			nxt[pre[mp[i]]]=nxt[nxt[mp[i]]];
//			for(int j=1; j<=n; ++j)
//				printf("%d ",a[j]);
//			putchar('\n');
//			for(int j=1; j<=n; ++j)
//				printf("%d: %d %d %d\n",j,mp[j],nxt[mp[j]],pre[mp[j]]);
//			putchar('\n');
		}
	for(int i=1; i<=tot; ++i)
		printf("%d ",ans[i]);
	return 0;
}


