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
struct node
{
	int s,t,k;
	inline bool friend operator <(const node &rhsa,const node &rhsb)
	{
		return rhsa.s==rhsb.s?rhsa.t<rhsb.t:rhsa.s<rhsb.s;
	}
} a[N];
int heap[N],heap_size;
inline void push(int val)
{
	heap[++heap_size]=val;
	int now=heap_size;
	while(now>1)
	{
		int nxt=now>>1;
		if(heap[nxt]>=heap[now])
			return;
		swap(heap[nxt],heap[now]);
		now=nxt;
	}
}
inline void pop()
{
	heap[1]=heap[heap_size--];
	int now=1;
	while(now*2<=heap_size)
	{
		int nxt=now*2;
		if(heap[nxt+1]>heap[nxt]&&nxt<heap_size)
			++nxt;
		if(heap[nxt]<=heap[now])
			break;
		swap(heap[nxt],heap[now]);
		now=nxt;
	}
}
inline void del(int pos)
{
	int now=pos;
	heap[pos]=heap[heap_size--];
	while(now>1)
	{
		int nxt=now>>1;
		if(heap[nxt]>=heap[now])
			return;
		swap(heap[nxt],heap[now]);
		now=nxt;
	}
	while(now>1)
	{
		int nxt=now>>1;
		if(heap[nxt]>=heap[now])
			return;
		swap(heap[nxt],heap[now]);
		now=nxt;
	}
}
int tmp[N];
signed main()
{
	freopen("home.in","r",stdin),freopen("home.out","w",stdout);
	int k,n,c;
	read(k,n,c);
	for(int i=1; i<=k; ++i)
		read(a[i].s,a[i].t,a[i].k);
	sort(a+1,a+1+k);
	int ans=0;
	for(int i=1; i<=k; ++i)
	{
		int cnt=heap_size;
		for(int j=1; j<=cnt; ++j)
			tmp[j]=heap[j];
		heap_size=0;
		for(int j=1; j<=cnt; ++j)
			if(tmp[j]>a[i].s)
				push(tmp[j]);
			else
				++ans;
		for(int j=1; j<=a[i].k; ++j)
		{
			if(heap_size<c)
				push(a[i].t);
			else
			{
				if(heap[1]>a[i].t)
				{
					pop();
					push(a[i].t);
				}
				else
					break;
			}
		}
	}
	printf("%d\n",ans+heap_size);
	return 0;
}
