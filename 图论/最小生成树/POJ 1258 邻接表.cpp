#pragma warning(disable:4996)

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 105;
const int inf = 0x3f3f3f3f;

struct node
{
	int to;
	int cost;
	node(int t, int c)
	{
		to = t;
		cost = c;
	}
	friend bool operator < (struct node a, struct node b)
	{
		return a.cost > b.cost;
	}
};

int n, ans, cnt;
int d[maxn];//距离向量
int vis[maxn];//标记数组
vector<node> v[maxn];

void prim()
{
	int i;
	priority_queue<node> q;
	fill(vis, vis + maxn, 0);
	fill(d, d + maxn, inf);
	d[0] = 0;
	q.push(node(0, 0));
	while (cnt<n && q.empty() != 1)
	{
		node t = q.top();
		q.pop();
		int pos = t.to;
		if (vis[pos])
			continue;
		vis[pos] = 1;
		ans += t.cost;
		cnt++;
		for (i = 0; i < v[pos].size(); i++)
		{
			node x = v[pos][i];
			if (!vis[x.to] && d[x.to] > x.cost)
			{
				d[x.to] = x.cost;
				q.push(node(x.to, d[x.to]));
			}
		}
	}
}

int main()
{
	int i, j, x;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i <= n; i++)
		{
			v[i].clear();
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &x);
				v[i].push_back(node(j, x));
			}
		}
		cnt = 0;
		ans = 0;
		prim();
		printf("%d\n", ans);
	}
	return 0;
}
