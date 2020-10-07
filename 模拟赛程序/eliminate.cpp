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
char str[N];
int a[N];
int ans=0;
inline void work()
{
	int len=0;
	scanf("%s",str+1);
	for(int i=1; str[i]; ++i)
		if(str[i]==str[i-1])
			a[len]=2;
		else
			a[++len]=1;
//	for(int i=1; i<=len; ++i)
//		printf("%d",a[i]);
//	putchar('\n');
	bool flag=true;
	for(int i=1; i<=len; ++i)
		if(a[i]==2)
			flag=false;
	if(flag)
		return;
	const int mid=(len+1)>>1;
	if(len&1)
	{
		if(a[mid]==2)
		{
			ans+=len/2+1;
			return;
		}
	}
	else
	{
		if(a[mid]==2||a[mid+1]==2)
		{
			ans+=len/2+1;
			return;
		}
	}
	int l=0,r=0;
	for(int i=mid; i>=1; --i)
		if(a[i]==2)
		{
			l=i;
			break;
		}
	for(int i=mid+1; i<=len; ++i)
		if(a[i]==2)
		{
			r=i;
			break;
		}
	if(!l)
		ans+=r;
	else if(!r)
		ans+=len-l+1;
	else
		ans+=max(r-l+1,len/2+1);
}
signed main()
{
	freopen("eliminate.in","r",stdin),freopen("eliminate.out","w",stdout);
	int n,m;
	read(n,m);
	for(int i=1; i<=m; ++i)
		work();
	printf("%d\n",ans);
	return 0;
}


