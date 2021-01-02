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
const int N=2e5+5;
char str[N],s[N];
int sum[N];
int cnt[N];
int ans[N];
struct node
{
	int sum,len,id;
	inline bool operator <(const node &rhs)const
	{
		return len<rhs.len;
	}
} a[N];
signed main()
{
	freopen("similar.in","r",stdin),freopen("similar.out","w",stdout);
	scanf("%s",str+1);
	int n=(int)strlen(str+1);
	for(int i=1; i<=n; ++i)
		sum[i]=sum[i-1]+str[i]-'0';
	int q;
	read(q);
	for(int i=1; i<=q; ++i)
	{
		scanf("%s",s+1);
		for(int j=1; s[j]; ++j,++a[i].len)
			a[i].sum+=s[j]-'0';
		a[i].id=i;
	}
	sort(a+1,a+1+q);
	for(int i=1; i<=q; ++i)
	{
		if(a[i].len==a[i-1].len)
			ans[a[i].id]=cnt[a[i].sum];
		else
		{
			memset(cnt,0,sizeof(cnt));
			for(int j=1; j<=n-a[i].len+1; ++j)
				++cnt[sum[j+a[i].len-1]-sum[j-1]];
			ans[a[i].id]=cnt[a[i].sum];
		}
	}
	for(int i=1; i<=q; ++i)
		printf("%d\n",ans[i]);
	return 0;
}


