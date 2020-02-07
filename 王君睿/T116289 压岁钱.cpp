#include<cstdio>
#define re register
#define ll long long
#define lowbit(x) (x&(-x))
using namespace std;
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
const int N=1e6+5;
int n;
int ans;
ll sum,add[N];
inline void work(int now)
{
	int opt;
	sum+=add[now];
	read(opt);
	if(opt==1)
	{
		int a;
		read(a);
		sum+=a;
	}
	else if(opt==2)
	{
		int a;
		read(a);
		if(sum>=a)
			sum-=a;
		else
			++ans;
	}
	else if(opt==3)
	{
		int a,b;
		read(a),read(b);
		if(b<=now)
			return;
		sum-=a;
		add[b]+=a;
	}
}
int main()
{
	read(n);
	for(re int i=1; i<=n; ++i)
		work(i);
	printf("%d\n",ans);
	return 0;
}
