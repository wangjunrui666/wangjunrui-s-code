#include<cstdio>
#include<cstring>
#define re register
using namespace std;
template<typename T>
inline void read(T&x)
{
	x=0;
	char s=getchar();
	bool f=false;
	while(!(s>='0'&&s<='9'))
	{
		if(s=='-')
			f=true;
		s=getchar();
	}
	while(s>='0'&&s<='9')
	{
		x=(x<<1)+(x<<3)+s-'0';
		s=getchar();
	}
	if(f)
		x=(~x)+1;
}
int n,q,a[1000010],conut,p;
int main()
{
	while(read(n),read(q),n&&q)
	{
		printf("CASE# %d:\n",++conut);
		for(re int i=1; i<=n; i++)
			read(a[i]);
		sort(a+1,a+1+n);
		while(q--)
		{
			p=lower_bound(a+1,a+1+n)-a-1;
			if(a[p]==x)
				printf("%d found at %d",x,p);
			else
				printf("%d not found",x);
		}
	}
	return 0;
}

