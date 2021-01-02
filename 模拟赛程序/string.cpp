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
const int N=55;
vector<string>f[N][N];
string str;
inline void update(vector<string>&x,vector<string>&y)
{
	if(x.size()<y.size())
		return;
	if(y.size()<x.size())
	{
		x=y;
		return;
	}
	for(int i=0; i<x.size(); ++i)
	{
		if(x[i]<y[i])
			return;
		if(x[i]>y[i])
		{
			x=y;
			return;
		}
	}
}
bool flag[26];
inline bool check(int l,int r)
{
	memset(flag,0,sizeof(flag));
	for(int i=l; i<=r; ++i)
		if(flag[str[i-1]-'a'])
			return false;
		else
			flag[str[i-1]-'a']=true;
	return true;
}
inline void work()
{
	cin>>str;
	int n=str.length();
	for(int i=0; i<=n; ++i)
		for(int j=0; j<=n; ++j)
			if(i|j)
			{
				f[i][j].clear();
				for(int k=0; k<=n; ++k)
					f[i][j].push_back("");
			}
	f[1][0].clear();
	f[1][0].push_back(str.substr(0,1));
//	for(int i=1; i<=n; ++i)
//		cout<<str.substr(i-1,1)<<endl;
	for(int i=2; i<=n; ++i)
	{
		if(check(1,i))
		{
			f[i][0].clear();
			f[i][0].push_back(str.substr(0,i));
		}
		for(int j=1; j<i; ++j)
			if(check(j+1,i))
			{
				vector<string>&ans=f[i][j];
				for(int k=0; k<j; ++k)
					update(ans,f[j][k]);
				ans.push_back(str.substr(j,i-j));
				sort(ans.begin(),ans.end());
//				cout<<j+1<<' '<<i<<' '<<str.substr(j,i)<<'\t';
			}
//		cout<<endl;
	}
//	for(int i=1; i<=n; ++i)
//	{
//		for(int j=0; j<i; ++j)
//			printf("%d ",f[i][j].size());
//		putchar('\n');
//	}
	vector<string>ans;
	ans=f[n][0];
	for(int i=1; i<n; ++i)
		update(ans,f[n][i]);
	cout<<ans.size()<<endl;
	for(auto s:ans)
		cout<<s<<' ';
	cout<<endl;
}
signed main()
{
	freopen("string.in","r",stdin),freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
		work();
	return 0;
}


