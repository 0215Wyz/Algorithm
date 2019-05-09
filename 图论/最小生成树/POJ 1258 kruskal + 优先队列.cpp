#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int n, q;

const int maxn = 105;

struct edge
{
	int from;
	int to;
	int dis;
	edge(int f, int t, int d) :from(f), to(t), dis(d) {};
	friend bool operator < (struct edge a, struct edge b)
	{
		return a.dis > b.dis;
	}
};



priority_queue<edge> pq;
int pre[maxn];
int ran[maxn];

void init()
{
	for (int i = 0; i <= n; i++)
	{
		pre[i] = i;
		ran[i] = 0;
	}
}

int find(int x)
{
	if (x == pre[x])
		return x;
	return pre[x] = find(pre[x]);
}

bool join(int x, int y)
{
	int a = find(x);
	int b = find(y);
	if (a == b)
		return false;
	if (ran[a] < ran[b])
	{
		pre[a] = b;
	}
	else
	{
		if (ran[a] == ran[b])
		{
			ran[a]++;
		}
		pre[b] = a;
	}
	return true;
}

int main()
{
	int i, j, x, ans;
	while (scanf("%d", &n) != EOF)
	{
		init();
		while (pq.empty() != 1)
		{
			pq.pop();
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				scanf("%d", &x);
				pq.push(edge(i, j, x));
			}
		}
		ans = 0;
		while (pq.empty() != 1)
		{
			int x = pq.top().from;
			int y = pq.top().to;
			int s = pq.top().dis;
			pq.pop();
			if (join(x, y))
			{
				ans += s;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
