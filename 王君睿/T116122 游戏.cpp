#include<cstdio>
#include<cmath>
#include<vector>
#include<cctype>
#include<map>
#include<random>
#include<ctime>
#define re register
#define ll long long
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
namespace IO
{
	const int SIZE=1<<25;
	char ibuf[SIZE],*iS,*iT;
#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,SIZE,stdin),iS==iT?EOF:*iS++):*iS++)
	template<typename T>
	inline void read(T & x)
	{
		x=0;
		bool b=false;
		char ch=gc();
		while(!isdigit(ch)&&ch^'-')
			ch=gc();
		if(ch=='-')
		{
			b=true;
			ch=gc();
		}
		while(isdigit(ch))
		{
			x=(x<<1)+(x<<3)+(ch^'0');
			ch=gc();
		}
		if(b)
			x=~x+1;
		return;
	}
#undef gc
	char Out[1<<30],*fe=Out,ch[25];
	int num=0;
	template<typename T>
	inline void write(T x)
	{
		if(!x)
			*fe++='0';
		if(x<0)
		{
			*fe++='-';
			x=-x;
		}
		while(x)
		{
			ch[++num]=x%10+'0';
			x/=10;
		}
		while(num)
			*fe++=ch[num--];
		*fe++='\n';
	}
	inline void write_str(char *s)
	{
		for(re int i=0; s[i]; i++)
			*fe++=s[i];
		*fe++='\n';
	}
	inline void flush()
	{
		fwrite(Out,1,fe-Out,stdout);
		fe=Out;
	}
}
//using namespace IO;
namespace quick
{
	template<typename T1,typename T2,typename T3>
	inline T1 quickpow(T1 a,T2 b,T3 n)
	{
		T1 res=1;
		while(b)
		{
			if(b&1)
				res=res*a%n;
			a=a*a%n;
			b>>=1;
		}
		return res;
	}
}
namespace Exlucus
{
	inline void exgcd(ll a,ll b,ll &d,ll &x,ll &y)
	{
		if(!b)
		{
			d=a;
			x=1;
			y=0;
			return;
		}
		exgcd(b,a%b,d,y,x);
		y-=a/b*x;
		return;
	}
	inline ll fac(ll n,ll pi,ll pk)
	{
		if(!n)
			return 1ll;
		ll res=1ll;
		for(re int i=2; i<=pk; ++i)
			if(i%pi)
				res=res*i%pk;
		res=quick::quickpow(res,n/pk,pk);
		for(re int i=2; i<=n%pk; ++i)
			if(i%pi)
				res=res*i%pk;
		return res*fac(n/pi,pi,pk)%pk;
	}
	inline ll inv(ll n,ll mod)
	{
		ll x,y,d;
		exgcd(n,mod,d,x,y);
		return (x%mod+mod)%mod;
	}
	inline ll CRT(ll b,ll mod,ll p)
	{
		return b*inv(p/mod,mod)%p*(p/mod)%p;
	}
	inline ll C(ll n,ll m,ll pi,ll pk)
	{
		ll up=fac(n,pi,pk),d1=fac(m,pi,pk),d2=fac(n-m,pi,pk),k=0;
		for(re ll i=n; i; i/=pi)
			k+=i/pi;
		for(re ll i=m; i; i/=pi)
			k-=i/pi;
		for(re ll i=n-m; i; i/=pi)
			k-=i/pi;
		return up*inv(d1,pk)%pk*inv(d2,pk)%pk*quick::quickpow(pi,k,pk)%pk;
	}
	inline ll exlucus(ll n,ll m,ll p)
	{
		ll res=0,tmp=p,pk;
		int lim=sqrt(p)+5;
		for(re int i=2; i<=lim; ++i)
			if(tmp%i==0)
			{
				pk=1;
				while(tmp%i==0)
				{
					pk*=i;
					tmp/=i;
				}
				res=(res+CRT(C(n,m,i,pk),pk,p))%p;
			}
		if(tmp>1)
			res=(res+CRT(C(n,m,tmp,tmp),tmp,p))%p;
		return res;
	}
}
namespace ExBSGS
{
#define mul(a,b,p) (1ll*a*b%p)
	template<typename T>
	inline T gcd(T a,T b)
	{
		return b?gcd(b,a%b):a;
	}
	map<ll,ll>Hash;
	inline ll exBSGS(ll a,ll b,ll p)
	{
		a%=p;
		b%=p;
		if(b==1)
			return 0;
		if(!b&&!a)
			return 1;
		if(!a)
			return -1;
		if(!b)
		{
			ll res=0,d;
			while((d=gcd(a,p))!=1)
			{
				++res;
				p/=d;
				if(p==1)
					return res;
			}
			return -1;
		}
		ll res=0,A=a,B=b,P=p,C=1,d;
		while((d=gcd(A,P))!=1)
		{
			if(B%d)
				return -1;
			P/=d;
			B/=d;
			C=mul(C,A/d,P);
			++res;
			if(C==B)
				return res;
		}
		Hash.clear();
		ll f=1,t=sqrt(P)+1;
		for(re int i=0; i<t; ++i)
		{
			Hash[mul(f,B,P)]=i;
			f=mul(f,A,P);
		}
		int tf=f;
		f=mul(f,C,P);
		for(re int i=1; i<=t; ++i)
		{
			if(Hash.find(f)!=Hash.end())
				return res+i*t-Hash[f];
			f=mul(f,tf,P);
		}
		return -1;
	}
#undef mul
}
#define N (int)1e6+5
class heap
{
	private:
		int heap[N],heap_size;
		int n;
	public:
		inline void push(int val)
		{
			heap[++heap_size]=val;
			int nxt,now=heap_size;
			while(now>1)
			{
				nxt=now>>1;
				if(heap[nxt]<=heap[now])
					break;
				swap(heap[nxt],heap[now]);
				now=nxt;
			}
		}
		inline void pop()
		{
			heap[1]=heap[heap_size--];
			int nxt,now=1;
			while((now<<1)<=heap_size)
			{
				nxt=now<<1;
				if(nxt<heap_size&&heap[nxt+1]<heap[nxt])
					++nxt;
				if(heap[now]<=heap[nxt])
					break;
				swap(heap[nxt],heap[now]);
				now=nxt;
			}
		}
		inline void work()
		{
			read(n);
			while(n--)
			{
				int opt;
				read(opt);
				if(opt==1)
				{
					int x;
					read(x);
					push(x);
				}
				else if(opt==2)
					printf("%d\n",heap[1]);
				else if(opt==3)
					pop();
			}
		}
} ;
mt19937 rnd((unsigned int)time(0));
class fhq_treap
{
	private:
		struct Tree
		{
			int val,key,size;
			int l,r;
		} tree[N];
		int cnt,root;
		inline int newnode(int val)
		{
			tree[++cnt].val=val;
			tree[cnt].key=rnd();
			tree[cnt].size=1;
			return cnt;
		}
		inline void update(int now)
		{
			tree[now].size=tree[tree[now].l].size+tree[tree[now].r].size+1;
			return;
		}
		inline void split(int now,int val,int &x,int &y)
		{
			if(!now)
				x=y=0;
			else
			{
				if(tree[now].val<=val)
				{
					x=now;
					split(tree[now].r,val,tree[now].r,y);
				}
				else
				{
					y=now;
					split(tree[now].l,val,x,tree[now].l);
				}
				update(now);
			}
			return;
		}
		inline int merge(int x,int y)
		{
			if(!x||!y)
				return x+y;
			if(tree[x].key>tree[y].key)
			{
				tree[x].r=merge(tree[x].r,y);
				update(x);
				return x;
			}
			else
			{
				tree[y].l=merge(x,tree[y].l);
				update(y);
				return y;
			}
		}
	public:
		inline void insert(int val)
		{
			int x,y;
			split(root,val,x,y);
			root=merge(merge(x,newnode(val)),y);
			return;
		}
		inline void del(int val)
		{
			int x,y,z;
			split(root,val,x,z);
			split(x,val-1,x,y);
			y=merge(tree[y].l,tree[y].r);
			root=merge(merge(x,y),z);
			return;
		}
		inline void getrank(int val)
		{
			int x,y;
			split(root,val-1,x,y);
			printf("%d\n",tree[x].size+1);
			root=merge(x,y);
			return;
		}
		inline void getnum(int rank)
		{
			int now=root;
			while(now)
			{
				if(rank==tree[tree[now].l].size+1)
					break;
				else if(tree[tree[now].l].size>=rank)
					now=tree[now].l;
				else
				{
					rank-=tree[tree[now].l].size+1;
					now=tree[now].r;
				}
			}
			printf("%d\n",tree[now].val);
			return;
		}
		inline void pre(int val)
		{
			int x,y;
			split(root,val-1,x,y);
			int now=x;
			while(tree[now].r)
				now=tree[now].r;
			printf("%d\n",tree[now].val);
			root=merge(x,y);
			return;
		}
		inline void next(int val)
		{
			int x,y;
			split(root,val,x,y);
			int now=y;
			while(tree[now].l)
				now=tree[now].l;
			printf("%d\n",tree[now].val);
			root=merge(x,y);
			return;
		}
		inline void getans()
		{
			int opt,val;
			read(opt),read(val);
			switch(opt)
			{
				case 1:
					insert(val);
					break;
				case 2:
					del(val);
					break;
				case 3:
					getrank(val);
					break;
				case 4:
					getnum(val);
					break;
				case 5:
					pre(val);
					break;
				case 6:
					next(val);
					break;
			}
		}
} ;
#undef N
const int N=1e6+5;
struct node
{
	int tail;
	ll sum;
} judge[N];
int n,a[N],k,where,w[N];
ll sum[N];
vector<int>ans;
inline void solve(int val)
{
	for(re int i=max(where+1,2); i<=n; ++i)
	{
		while(judge[i].sum+a[judge[i].tail]<=val&&judge[i].tail<=n)
			judge[i].sum+=a[judge[i].tail++];
	}
	if(sum[n]<=val)
	{
		ans.push_back(val);
		return;
	}
	for(re int i=where+1; i<n; ++i)
	{
		if(sum[i]>val)
			return;
		if(sum[i]>judge[i+1].sum)
		{
			ans.push_back(val);
			return;
		}
		where=i;
	}
}
int main()
{
	read(n);
	for(re int i=1; i<=n; ++i)
	{
		read(a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	read(k);
	if(n<=3333&&k<=3333)
	{
		for(re int i=2; i<=n; ++i)
			judge[i].tail=i;
		for(re int i=1; i<=k; ++i)
			solve(i);
	}
	else
	{
		int l=0,r=1,sum1=0,sum2=a[1];
		while(l<n&&sum1+a[l+1]<=k)
		{
			sum1+=a[++l];
			sum2-=a[l];
			while(sum2+a[r+1]<sum1&&r<n)sum2+=a[++r];
			if(sum1<=min(sum2+a[r+1],k+1))
				w[sum1]++,w[min(sum2+a[r+1],k+1)]--;


		}
		if(l==n)w[sum1]++;
		int res=0;
		for(int i=0; i<=k; i++)
		{
			res+=w[i];
			if(res)
				ans.push_back(i);
		}
	}
	printf("%d\n",ans.size());
	for(re int i=0; i<ans.size(); ++i)
		printf("%d ",ans[i]);
	return 0;
}/*#include <cstdio>
			#include <vector>
			#include <algorithm>
			#include <cstring>
			#include <cctype>

			using namespace std;

			template <typename T>
			inline void read(T &x)
			{
			x = 0;
			char s = getchar();
			bool f = false;
			while (!(s >= '0' && s <= '9'))
			{
			if (s == '-')
			f = true;
			s = getchar();
			}
			while (s >= '0' && s <= '9')
			{
			x = (x << 1) + (x << 3) + s - '0';
			s = getchar();
			}
			if (f)
			x = (~x) + 1;
			}

			namespace OUT
			{

			char Out[1 << 25], *fe = Out, ch[25];
			int num = 0;

			template <typename T>
			inline void write(T x)
			{
			if (!x)
			*fe++ = '0';
			if (x < 0)
			{
			*fe++ = '-';
			x = -x;
			}
			while (x)
			{
			ch[++num] = x % 10 + '0';
			x /= 10;
			}
			while (num) *fe++ = ch[num--];
			*fe++ = '\n';
			}

			inline void flush()
			{
			fwrite(Out, 1, fe - Out, stdout);
			fe = Out;
			}
			}  // namespace OUT
			using namespace OUT;

			#define re register
			#define ll long long
			#define ls (k << 1)
			#define rs (k << 1 | 1)
			#define node vector<int>

			const int N = 1e5 + 10, S = 40;

			int n, q, mod, phi, pcnt, a[N];

			vector<int> pm;

			struct Tree
			{
			int c[S], sum, mul, high;  // high是剩余的数
			} tree[N << 2];

			inline node dec(int n)  //质因数分解
			{
			node res;
			res.clear();
			for (re int i = 2; i * i <= n; i++)
			while (n % i == 0)
			{
			n /= i;
			res.push_back(i);
			}
			if (n > 1)
			res.push_back(n);
			return res;
			}

			inline void Unique(node &res)  //质因数去重(血的教训)
			{
			sort(res.begin(), res.end());
			int u = unique(res.begin(), res.end()) - res.begin();
			while (res.size() > u) res.pop_back();
			}

			inline int getphi(int n)  //欧拉函数
			{
			int ans = n;
			for (re int i = 2; i * i <= n; i++)
			if (n % i == 0)
			{
			ans = ans / i * (i - 1);
			while (n % i == 0) n /= i;
			}
			if (n > 1)
			ans = ans / n * (n - 1);
			return ans;
			}

			inline int pow(int a, int b, int mod = ::mod)
			{
			int ans = 1;
			for (; b; b >>= 1, a = (ll)a * a % mod)
			if (b & 1)
			ans = (ll)ans * a % mod;
			return ans;
			}

			inline int inv(int x)
			{
			return pow(x, phi - 1);
			}

			inline void get(int res, int &ans, int *c)
			{
			for (re int i = 1; i <= pcnt; i++)
			while (res % pm[i - 1] == 0)
			{
			res /= pm[i - 1];
			c[i]++;
			}
			ans = res % mod;
			}

			inline int calc(int v, int *dev)
			{
			for (re int i = 1; i <= pcnt; i++) v = (ll)v * pow(pm[i - 1], dev[i]) % mod;
			return v;
			}

			inline void pushdown(int k)
			{
			for (re int i = 1; i <= pcnt; i++)
			{
			tree[ls].c[i] += tree[k].c[i];
			tree[rs].c[i] += tree[k].c[i];
			tree[k].c[i] = 0;
			}
			tree[ls].sum = (ll)tree[ls].sum * tree[k].mul % mod;
			tree[rs].sum = (ll)tree[rs].sum * tree[k].mul % mod;
			tree[ls].mul = (ll)tree[ls].mul * tree[k].mul % mod;
			tree[rs].mul = (ll)tree[rs].mul * tree[k].mul % mod;
			tree[ls].high = (ll)tree[ls].high * tree[k].high % mod;
			tree[rs].high = (ll)tree[rs].high * tree[k].high % mod;
			tree[k].mul = tree[k].high = 1;
			}

			inline void pushup(int k)
			{
			tree[k].sum = (tree[ls].sum + tree[rs].sum) % mod;
			}

			inline void build(int k, int l, int r)
			{
			tree[k].mul = tree[k].high = 1;
			memset(tree[k].c, 0, sizeof(tree[k].c));
			if (l == r)
			{
			tree[k].sum = a[l] % mod;
			get(a[l], tree[k].high, tree[k].c);
			return;
			}
			int mid = l + r >> 1;
			build(ls, l, mid);
			build(rs, mid + 1, r);
			pushup(k);
			}

			inline void update1(int k, int l, int r, int x, int y, int v, int *dev, int high)
			{
			if (r < x || l > y)
			return;
			if (x <= l && r <= y)
			{
			for (re int i = 1; i <= pcnt; i++) tree[k].c[i] += dev[i];
			tree[k].sum = (ll)tree[k].sum * v % mod;
			tree[k].mul = (ll)tree[k].mul * v % mod;
			tree[k].high = (ll)tree[k].high * high % mod;
			return;
			}
			pushdown(k);
			int mid = l + r >> 1;
			update1(ls, l, mid, x, y, v, dev, high);
			update1(rs, mid + 1, r, x, y, v, dev, high);
			pushup(k);
			}

			inline void update2(int k, int l, int r, int pos, int v, int *dev, int high)
			{
			if (l == r)
			{
			tree[k].high = (ll)tree[k].high * inv(high) % mod;
			for (re int i = 1; i <= pcnt; i++) tree[k].c[i] -= dev[i];
			tree[k].sum = calc(tree[k].high, tree[k].c);
			return;
			}
			pushdown(k);
			int mid = l + r >> 1;
			if (pos <= mid)
			update2(ls, l, mid, pos, v, dev, high);
			else
			update2(rs, mid + 1, r, pos, v, dev, high);
			pushup(k);
			}

			inline int query(int k, int l, int r, int x, int y)
			{
			if (r < x || l > y)
			return 0;
			if (x <= l && r <= y)
			return tree[k].sum;
			pushdown(k);
			int mid = l + r >> 1;
			return (query(ls, l, mid, x, y) + query(rs, mid + 1, r, x, y)) % mod;
			}

			int main()
			{
			read(n), read(mod), phi = getphi(mod);
			for (re int i = 1; i <= n; i++) read(a[i]);
			pm = dec(mod);
			Unique(pm);
			pcnt = pm.size();
			build(1, 1, n);
			read(q);
			for (re int i = 1, c[S], opt, a, b, x, v; i <= q; i++)
			{
			read(opt), read(a), read(b);
			memset(c, 0, sizeof(c));
			if (opt == 1)
			{
			read(x);
			get(x, v, c);
			update1(1, 1, n, a, b, x, c, v);
			}
			else if (opt == 2)
			{
			get(b, v, c);
			update2(1, 1, n, a, b, c, v);
			}
			else if (opt == 3)
			write(query(1, 1, n, a, b));
			}
			flush();
			return 0;
			}*/
/*
* ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
* │Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│  ┌┐    ┌┐    ┌┐
* └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘  └┘    └┘    └┘
* ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
* │~ `│! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│ BacSp │ │Ins│Hom│PUp│ │Num│ / │ * │ - │
* ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
* │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│ │ 7 │ 8 │ 9 │   │
* ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + │
* │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  │               │ 4 │ 5 │ 6 │   │
* ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
* │ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│  Shift   │     │ ↑ │     │ 1 │ 2 │ 3 │   │
* ├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ E││
* │ Ctrl│ Win│ Alt│         Space         │ Alt│ Win│Menu│Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │←─┘│
* └─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
*/
/*#include<cstdio>
#include<cstdlib>
#include<iostream>
#define re register
using namespace std;
#define dipig(x,y) ((a[x].tp=='M'&&(a[y].t==2||a[y].t==3))||(a[x].tp=='Z'&&a[y].t==2)||(a[x].tp=='F'&&a[y].t==1))
#define youpig(x,y) (((a[x].tp=='M'||a[x].tp=='Z')&&a[y].t==1)||(a[x].tp=='F'&&a[y].t==2))
int nxt[15],las[15],top,f,n,m;
char tmp[5],paidui[2010];
struct pig
{
	char tp,pai[2010];
	int xue,s,z,t;
	inline void chess(int &x)
	{
		--s;
		for(re int i=x; i<s; ++i)
			pai[i]=pai[i+1];
		--x;
	}
	inline bool search(char ch)
	{
		for(re int i=0; i<s; ++i)
			if(pai[i]==ch)
			{
				chess(i);
				return true;
			}
		return false;
	}
	inline void mopai(int x)
	{
		for(re int i=1; i<=x; ++i)
		{
			pai[s++]=paidui[top++];
			if(top==m)
				--top;
		}
	}
} a[15];
inline void end()
{
	puts(a[1].xue?"MP":"FP");
	for(int i=1; i<=n; i++)
	{
		if(a[i].xue==0)puts("DEAD");
		else
		{
			for(int j=0; j<a[i].s-1; j++)
				printf("%c ",a[i].pai[j]);
			if(a[i].s)printf("%c",a[i].pai[a[i].s-1]);
			puts("");
		}
	}
	exit(0);
}
inline void killed(int g,int p)
{
	if(a[p].tp=='M')end();
	if(a[p].tp=='F')
	{
		if(!--f)end();
		a[g].mopai(3);
	}
	else if(a[p].tp=='Z'&&a[g].tp=='M')a[g].s=a[g].z=0;
	nxt[las[p]]=nxt[p];
	las[nxt[p]]=las[p];
}
inline void kouxue(int x,int y)
{
	a[y].xue--;
	if(!a[y].xue)a[y].xue+=a[y].search('P');
	if(!a[y].xue)killed(x,y);
}
inline bool wxkj(int s,int x)
{
	for(int i=s,f=0; !f||i!=s; i=nxt[i],f=1)
	{
		if((!x?(dipig(i,s)):(youpig(i,x)))&&a[i].search('J'))
		{
			a[i].t=a[i].tp=='F'?2:1;
			return !wxkj(i,0);
		}
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(re int i=1; i<=n; i++)
	{
		scanf("%s",tmp);
		a[i].tp=tmp[0];
		f+=tmp[0]=='F';
		for(int j=0; j<4; j++)
			cin>>a[i].pai[j];
		nxt[i]=i+1,las[i]=i-1;
		a[i].s=a[i].xue=4;
	}
	for(re int i=0; i<m; i++)
		cin>>paidui[i];
	nxt[n]=1,las[1]=n;
	int now=1;
	a[1].t=1;
	if(!f)end();
	while(1)
	{
		int kill=0;
		a[now].mopai(2);
		for(re int i=0; i<a[now].s&&a[now].xue; i++)
		{
			if(a[now].pai[i]=='Z')
			{
				a[now].z=1,a[now].chess(i);
				i=-1;
			}
			else if(a[now].pai[i]=='P'&&a[now].xue<4)
			{
				a[now].xue++,a[now].chess(i);
			}
			else if(a[now].pai[i]=='K'&&(a[now].z||!kill))
			{
				int nx=nxt[now];
				if(dipig(now,nx))
				{
					a[now].t=a[now].tp=='F'?2:1;
					a[now].chess(i);
					kill=1;
					if(!a[nx].search('D'))kouxue(now,nx);
				}
			}
			else if(a[now].pai[i]=='F')
			{
				for(re int j=a[now].tp=='F'?1:nxt[now]; j!=now; j=nxt[j])
					if(dipig(now,j))
					{
						a[now].chess(i);
						a[now].t=a[now].tp=='F'?2:1;
						if(wxkj(now,j))break;
						if(a[j].tp=='Z'&&a[now].tp=='M')
						{
							kouxue(now,j);
							break;
						}
						int t=1;
						while(1)
						{
							if(t==1)
							{
								if(!a[j].search('K'))
								{
									kouxue(now,j);
									break;
								}
							}
							else if(!a[now].search('K'))
							{
								kouxue(j,now),i=max(-1,i-1);
								break;
							}
							t^=1;
						}
						i=-1;
						break;
					}
			}
			else if(a[now].pai[i]=='N'||a[now].pai[i]=='W')
			{
				char ch=a[now].pai[i];
				a[now].chess(i);
				for(re int j=nxt[now]; j!=now; j=nxt[j])
				{
					if(!wxkj(now,j)&&!a[j].search(ch=='N'?'K':'D'))
					{
						if(a[j].tp=='M'&&!a[now].t)a[now].t=3;
						kouxue(now,j);
					}
				}
				i=-1;
			}
		}
		now=nxt[now];
	}
	return 0;
}*/
