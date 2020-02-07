#include<cstdio>
#define re register
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
int a[N];
int sum;
int judge[15];
int main()
{
	read(n);
	for(re int i=1; i<=n; ++i)
	{
		read(a[i]);
		a[i]%=10;
		sum=(sum+a[i])%10;
		++judge[a[i]];
	}
	for(re int i=0; i<=9; ++i)
	{
		int a=i,b=(sum-i+10)%10;
		if(a==b)
		{
			if(judge[a]>1)
			{
				printf("%d\n",sum==0?10:sum);
				return 0;
			}
		}
		else if(judge[a]&&judge[b])
		{
			printf("%d\n",sum==0?10:sum);
			return 0;
		}
	}
	printf("0\n");
	return 0;


}
