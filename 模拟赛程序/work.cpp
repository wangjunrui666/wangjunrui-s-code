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
#define node vector<int>
using namespace std;
const int N=20+5,INF=0x3f3f3f3f;
struct Node
{
	string s;
	int d,c;
	inline bool operator <(const Node &rhs)const
	{
		return s<rhs.s;
	}
} a[N];
node g[(1<<20)+5];
pair<int,int>f[(1<<20)+5];
inline void work()
{
	int n;
	cin>>n;
	for(int i=0; i<n; ++i)
		cin>>a[i].s>>a[i].d>>a[i].c;
	sort(a,a+n);
	f[0]=make_pair(0,0);
	for(int S=1; S<(1<<n); ++S)
		f[S]=make_pair(INF,INF);
	for(int now=0; now<n; ++now)
	{
		for(int S=0; S<(1<<n); ++S)
		{
			int cnt=0;
			for(int i=0; i<n; ++i)
				if((S>>i)&1)
					++cnt;
			if(cnt!=now)
				continue;
			for(int i=0; i<n; ++i)
			{
				if((S>>i)&1)
					continue;
				int nxtS=S|(1<<i),nxtday=f[S].second+a[i].c,
				    nxtval=f[S].first+max(0,nxtday-a[i].d);
				node ans=g[S];
				ans.push_back(i);
				if(f[nxtS].first>nxtval||(f[nxtS].first==nxtval&&g[nxtS]>ans))
				{
					f[nxtS]=make_pair(nxtval,nxtday);
					g[nxtS]=ans;
				}
			}
		}
	}
	cout<<f[(1<<n)-1].first<<endl;
	for(auto v:g[(1<<n)-1])
		cout<<a[v].s<<endl;
}
signed main()
{
	freopen("work.in","r",stdin),freopen("work.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
		work();
	return 0;
}
