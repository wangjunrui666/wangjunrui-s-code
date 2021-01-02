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
int n,L[N],R[N];
struct node
{
	int id,val;
	node(int _id=0,int _val=0):id(_id),val(_val) {}
};
struct Queue
{
	node q[N];
	int head,tail;
	inline void update(node val)
	{
		while(head<=tail&&q[tail].val<val.val)
			--tail;
		q[++tail]=val;
	}
	inline void update(int id)
	{
		while(head<=tail&&q[head].id<=id)
			++head;
	}
	inline int calc()
	{
		if(head>tail)
			return ~0x7fffffff;
		return q[head].val;
	}
} q;
signed main()
{
	freopen("temperature.in","r",stdin),freopen("temperature.out","w",stdout);
	read(n);
	for(int i=1; i<=n; ++i)
		read(L[i],R[i]);
	q.update(node(1,L[1]));
	int r=1;
	int ans=0;
	for(int l=1; l<=n; ++l)
	{
		while(r<n&&q.calc()<=R[r+1])
		{
			++r;
			q.update(node(r,L[r]));
		}
		ans=max(ans,r-l+1);
//		printf("%d %d\n",l,r);
//			printf("%d ",q.q[j].val);
//		putchar('\n');
		q.update(l);
	}
	printf("%d\n",ans);
	return 0;
}


