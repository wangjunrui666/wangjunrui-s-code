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
const int N=2e7+5;
int n,k,p;
int block,num,belong[N],L[N],R[N];
int a[N];
int pre[N],suf[N];
#define mul(x,y) ((int)((ll)x*y%p))
inline void build()
{
	block=k;
	num=n/block+(n%block!=0);
	for(int i=1; i<=num; ++i)
	{
		L[i]=R[i-1]+1;
		R[i]=R[i-1]+block;
		if(i==num)
			R[i]=n;
		for(int j=L[i]; j<=R[i]; ++j)
			belong[j]=i;
		pre[L[i]]=a[L[i]];
		for(int j=L[i]+1; j<=R[i]; ++j)
			pre[j]=mul(pre[j-1],a[j]);
		suf[R[i]]=a[R[i]];
		for(int j=R[i]-1; j>=L[i]; --j)
			suf[j]=mul(suf[j+1],a[j]);
	}
}
inline int query(int x,int y)
{
	if(belong[x]==belong[y])
		return pre[y];
	else
		return mul(suf[x],pre[y]);
}
signed main()
{
	freopen("range.in","r",stdin),freopen("range.out","w",stdout);
	read(n,k,p);
	int A,B,C,D;
	read(A,B,C,D);
	a[1]=A;
	for(int i=2; i<=n; ++i)
		a[i]=(int)(((ll)a[i-1]*B+C)%D);
	build();
	int ans=0;
	for(int i=1; i+k-1<=n; ++i)
		ans^=query(i,i+k-1);
	printf("%d\n",ans);
	return 0;
}


