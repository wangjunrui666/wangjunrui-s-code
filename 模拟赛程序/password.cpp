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
class SAM
{
	public:
		struct Point
		{
			int fa,len,ch[26];
		} point[N];
		int las=1,tot=1;
		ll f[N];
		inline void insert(int c)
		{
			int p=las,np=las=++tot;
			f[np]=1;
			point[np].len=point[p].len+1;
			for(; p&&!point[p].ch[c]; p=point[p].fa)
				point[p].ch[c]=np;
			if(!p)
				point[np].fa=1;
			else
			{
				int q=point[p].ch[c];
				if(point[q].len==point[p].len+1)
					point[np].fa=q;
				else
				{
					int nq=++tot;
					point[nq]=point[q];
					point[nq].len=point[p].len+1;
					point[np].fa=point[q].fa=nq;
					for(; p&&point[p].ch[c]==q; p=point[p].fa)
						point[p].ch[c]=nq;
				}
			}
		}
		vector<int>g[N];
		inline void build()
		{
			for(int i=2; i<=tot; ++i)
				g[point[i].fa].push_back(i);
		}
		inline void dfs(int u)
		{
			for(auto v:g[u])
			{
				dfs(v);
				f[u]+=f[v];
			}
		}
		inline ll query(string s)
		{
			int now=1;
			for(auto v:s)
				if(point[now].ch[v-'a'])
					now=point[now].ch[v-'a'];
				else
					return 0;
			return f[now];
		}
} ;
SAM tree[15];
int n,a[N];
string s[N],q[N];
signed main()
{
	freopen("password.in","r",stdin),freopen("password.out","w",stdout);
	ios::sync_with_stdio(false);
	int m,q;
	cin>>m;
	for(int i=1; i<=m; ++i)
		cin>>s[i];
	for(int i=1; i<=m; ++i)
		cin>>a[i];
	for(int i=m+1; i<=10; ++i)
	{
		for(int j=1; j<=m; ++j)
			s[i]+=s[i-m-1+j];
	}
	for(int i=1; i<=10; ++i)
	{
		for(auto v:s[i])
			tree[i].insert(v-'a');
		tree[i].build();
		tree[i].dfs(1);
	}
	cin>>q;
	while(q--)
	{
		string T;
		int id;
		cin>>T>>id;
		printf("%d\n",tree[id].query(T));
	}
	return 0;
}


