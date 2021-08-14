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
#define ws wdnmd
int wa[N],wb[N],ws[N],sa[N],rk[N],height[N];
inline bool cmp(int *r,int a,int b,int l)
{
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
inline void suffix_array(char *str,int n,int m)
{
	int *x=wa,*y=wb;

	fill(ws+1,ws+1+m,0);
	for(int i=1; i<=n; ++i)
		++ws[x[i]=str[i]-'a'+1];
	for(int i=2; i<=m; ++i)
		ws[i]+=ws[i-1];
	for(int i=n; i>=1; --i)
		sa[ws[x[i]]--]=i;

	for(int p=0,j=1; j<n&&p<=n; j<<=1,m=p)
	{
		p=0;
		for(int i=n; i>=n-j+1; --i)
			y[++p]=i;
		for(int i=1; i<=n; ++i)
			if(sa[i]>j)
				y[++p]=sa[i]-j;

		fill(ws+1,ws+1+m,0);
		for(int i=1; i<=n; ++i)
			++ws[x[i]];
		for(int i=2; i<=m; ++i)
			ws[i]+=ws[i-1];
		for(int i=n; i>=1; --i)
			sa[ws[x[y[i]]]--]=y[i];

		p=0;
		swap(x,y);
		for(int i=1; i<=n; ++i)
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p:++p;
	}

	for(int i=1; i<=n; ++i)
		rk[sa[i]]=i;

	for(int i=1,j=0; i<=n; ++i)
	{
		if(j)
			--j;
		while(str[i+j]==str[sa[rk[i]-1]+j])
			++j;
		height[rk[i]]=j;
	}
}
char str[N];
int n;
inline void work()
{
	scanf("%s",str+1);
	n=(int)strlen(str+1);
	suffix_array(str,n,26);

	int ans=0;
	for(int i=2; i<=n; ++i)
		ans=max(ans,height[i]);
	printf("%d\n",ans);
}
signed main()
{
	int T;
	read(T);
	while(T--)
		work();
	return 0;
}


