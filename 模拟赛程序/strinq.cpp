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
const int N=3e4+5;
char a[N],b[N];
inline void work()
{
	scanf("%s%s",a+1,b+1);
	int i=1,j=1;
	for(; a[i]&&b[j];)
	{
		while(a[i]=='*')
			++i;
		if(!a[i])
			break;
		char c=a[i];
		int cnt1=0,cnt2=0;
		bool flag=false;
		while(a[i]==c||a[i]=='*')
		{
			if(a[i]=='*')
				flag=true;
			else
				++cnt1;
			++i;
		}
		while(b[j]==c)
		{
			++j;
			++cnt2;
		}
//		printf("%d %d %d\n",cnt1,cnt2,flag);
		if(cnt1>cnt2)
		{
			printf("No\n");
			return;
		}
		else if(cnt1<cnt2&&(!flag||(cnt1&&a[i]=='*')))
		{
			printf("No\n");
			return;
		}
	}
	if(a[i]||b[j])
		printf("No\n");
	else
		printf("Yes\n");
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
}
signed main()
{
	freopen("strinq.in","r",stdin),freopen("strinq.out","w",stdout);
	int T;
	read(T);
	while(T--)
		work();
	return 0;
}


