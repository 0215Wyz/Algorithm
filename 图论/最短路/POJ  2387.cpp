#pragma warning(disable:4996)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1005;
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

int T, N;
int d[maxn];
int vis[maxn];
vector<node> v[maxn];

void dijkstra()
{
	int i;
	priority_queue<node> q;
	fill(d, d + maxn, inf);
	fill(vis, vis + maxn, 0);
	d[N] = 0;
	q.push(node(N, 0));
	while (q.empty() != 1)
	{
		node t = q.top();
		q.pop();
		int pos = t.to;
		if (vis[pos])
			continue;
		vis[pos] = 1;
		for (i = 0; i < v[pos].size(); i++)
		{
			node  x = v[pos][i];
			if (d[x.to] > d[pos] + x.cost)
			{
				d[x.to] = d[pos] + x.cost;
				q.push(node(x.to, d[x.to]));
			}
		}
	}
}

int main()
{
	int i, a, b, c;
	while (scanf("%d%d", &T, &N) != EOF)
	{
		for (i = 0; i <= N; i++)
		{
			v[i].clear();
		}
		for (i = 0; i < T; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			v[a].push_back(node(b, c));
			v[b].push_back(node(a, c));
		}
		dijkstra();
		printf("%d\n", d[1]);
	}
	return 0;
}


