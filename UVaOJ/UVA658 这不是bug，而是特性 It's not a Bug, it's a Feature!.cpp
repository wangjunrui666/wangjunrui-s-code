#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int MAXB = 25, MAXP = 105, inf = 0x3f3f3f3f;

struct Heapnode
{
	int bug, dist;
	Heapnode() {}
	Heapnode(int bug, int dist)
	{
		this->bug = bug;
		this->dist = dist;
	}
	bool operator < (const Heapnode &rhs) const
	{
		return dist > rhs.dist;
	}
};

char before[MAXP][MAXB], after[MAXP][MAXB];
int t[MAXP], d[1 << MAXB], vis[1 << MAXB],sum;
int n, m;

inline int Dijkstra()
{
	for(int i = 0; i < (1 << n); i++)
		d[i] = inf, vis[i] = 0;

	priority_queue<Heapnode> Q;
	Q.push(Heapnode((1 << n) - 1, 0));
	d[(1 << n) - 1] = 0;

	while(!Q.empty())
	{
		Heapnode tmp = Q.top();
		Q.pop();
		//printf("%d\n",tmp.bug);
		if(tmp.bug == 0) return tmp.dist;
		if(vis[tmp.bug]) continue;
		vis[tmp.bug] = 1;

		for(int i = 0; i < m; i++)
		{
			int ok = 1;
			for(int j = 0; j < n; j++)
			{
				if(before[i][j] == '-' && ((1 << j) & tmp.bug)) ok = 0;
				if(before[i][j] == '+' && !((1 << j) & tmp.bug)) ok = 0;
			}
			if(ok)
			{
				sum++;
				int bug = tmp.bug;
				for(int j = 0; j < n; j++)
					if(after[i][j] == '-') bug &= ~(1 << j);
					else if(after[i][j] == '+') bug |= 1 << j;
				//printf("%d\n",bug);
				//printf("%d %d\n",tmp.bug,bug);
				if(d[bug] > tmp.dist + t[i])
				{
					d[bug] = tmp.dist + t[i];
					//printf("%d\n",bug);
					Q.push(Heapnode(bug, d[bug]));
				}
			}
		}
	}/*
	for(int i=0; i<=(1<<n)-1; i++)
		printf("%d ",d[i]);
	putchar('\n');*/
	//printf("%d\n",sum);
	return -1;
}

int main()
{
	int T = 0;
	while(scanf("%d %d", &n, &m) == 2 && n)
	{
		for(int i = 0; i < m; i++)
			scanf("%d%s%s", &t[i], before[i], after[i]);

		int ans  = Dijkstra();
		printf("Product %d\n", ++T);
		if(ans < 0) printf("Bugs cannot be fixed.\n\n");
		else printf("Fastest sequence takes %d seconds.\n\n", ans);
	}
	return 0;
}
