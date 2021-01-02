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
const int N=25;
int n,q;
int a[N];
struct node
{
	int opt,l,r,d;
} Q[N];
struct Ans
{
	int a[N],flag;
	inline int calc()
	{
		int ans=0;
		for(int i=1; i<=n; ++i)
			ans=ans|a[i];
		return ans;
	}
} ans,now,tmp;
inline void print()
{
	for(int i=1; i<=n; ++i)
		printf("%d ",now.a[i]);
	putchar('\n');
	if(now.calc()>ans.calc())
	{
		tmp=now;
		for(int i=1; i<=q; ++i)
		{
			if(Q[i].opt==1)
			{
				int maxx=0;
				for(int j=Q[i].l; j<=Q[i].r; ++j)
					maxx=max(maxx,tmp.a[i]);
				if(maxx!=Q[i].d)
					return;
			}
			else
				tmp.a[Q[i].l]=Q[i].d;
		}
		ans=now;
	}
}
inline void dfs(int pos)
{
	if(pos>n)
	{
		print();
		return ;
	}
	for(int i=0; i<=20; ++i)
	{
		now.a[pos]=i;
		dfs(pos+1);
	}
}
signed main()
{
	read(n,q);
	for(int i=1; i<=q; ++i)
	{
		read(Q[i].opt);
		if(Q[i].opt==1)
			read(Q[i].l,Q[i].r,Q[i].d);
		else
			read(Q[i].l,Q[i].d);
	}
	now.flag=true;
	dfs(1);
	if(ans.flag)
	{
		printf("YES\n");
		for(int i=1; i<=n; ++i)
			printf("%d ",ans.a[i]);
	}
	else
		printf("NO\n");
	return 0;
}


