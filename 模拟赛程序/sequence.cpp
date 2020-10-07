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
const int N=3e5+5;
int n,dp[N][4],a[N][3];
inline void updatemax(int &x,int y)
{
	if(x<y)
		x=y;
}
int p[N],tot;
struct Tree_array
{
	int maxx[N];
	inline void update(int pos,int val)
	{
		assert(pos>0);
		for(int i=pos; i<=tot; i+=lowbit(i))
			updatemax(maxx[i],val);
	}
	inline int query(int pos)
	{
		int res=0;
		for(int i=pos; i; i-=lowbit(i))
			updatemax(res,maxx[i]);
		return res;
	}
} pre[4],suf[4];
signed main()
{
	freopen("sequence.in","r",stdin),freopen("sequence.out","w",stdout);
	read(n);
	for(int i=1; i<=n; ++i)
	{
		read(a[i][0]);
		p[++tot]=a[i][0];
	}
	for(int i=1; i<=n; ++i)
	{
		read(a[i][1]);
		p[++tot]=a[i][1];
	}
	for(int i=1; i<=n; ++i)
	{
		read(a[i][2]);
		p[++tot]=a[i][2];
	}
	sort(p+1,p+1+tot);
	tot=(int)(unique(p+1,p+1+tot)-p-1);
	for(int i=1; i<=n; ++i)
		for(int j=0; j<3; ++j)
			a[i][j]=(int)(lower_bound(p+1,p+1+tot,a[i][j])-p);
//	printf("%d\n",tot);
//	for(int j=0; j<3; ++j)
//	{
//		for(int i=1; i<=n; ++i)
//			printf(" %d",a[i][j]);
//		putchar('\n');
//	}
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		dp[i][0]=1;
		dp[i][1]=1;
		dp[i][2]=1;
		dp[i][3]=1;

		updatemax(dp[i][0],max(max(pre[0].query(a[i][0]),pre[1].query(a[i][0])),
		                       max(pre[2].query(a[i][0]),pre[3].query(a[i][0])))+1);
		updatemax(dp[i][1],max(max(suf[0].query(tot-a[i][1]+1),suf[1].query(tot-a[i][1]+1)),
		                       max(suf[2].query(tot-a[i][1]+1),suf[3].query(tot-a[i][1]+1)))+1);
		updatemax(dp[i][2],max(max(pre[0].query(a[i][2]),pre[1].query(a[i][2])),
		                       pre[2].query(a[i][2]))+1);
		updatemax(dp[i][3],max(max(suf[0].query(tot-a[i][2]+1),suf[1].query(tot-a[i][2]+1)),
		                       suf[3].query(tot-a[i][2]+1))+1);
//		printf("%d %d %d %d",suf[3].query(6),suf[0].query(tot-a[i][2]+1),suf[1].query(tot-a[i][2]+1),suf[3].query(tot-a[i][2]+1));
		pre[0].update(a[i][0],dp[i][0]);
		pre[1].update(a[i][1],dp[i][1]);
		pre[2].update(a[i][2],dp[i][2]);
		pre[3].update(a[i][2],dp[i][3]);

//		printf(" --------? %d %d %d",tot-a[i][0]+1,tot-a[i][1]+1,tot-a[i][2]+1);
		suf[0].update(tot-a[i][0]+1,dp[i][0]);
		suf[1].update(tot-a[i][1]+1,dp[i][1]);
		suf[2].update(tot-a[i][2]+1,dp[i][2]);
		suf[3].update(tot-a[i][2]+1,dp[i][3]);
		ans=max(ans,max(max(dp[i][0],dp[i][1]),max(dp[i][2],dp[i][3])));
//		printf(" --------? %d %d %d %d\n",dp[i][0],dp[i][1],dp[i][2],dp[i][3]);
	}
//	for(int i=1; i<=n; ++i)
//	{
//		printf("%d %d %d %d\n",dp[i][0],dp[i][1],dp[i][2],dp[i][3]);
//	}
	printf("%d\n",ans);
	return 0;
}


