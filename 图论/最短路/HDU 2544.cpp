//HDU 2544 Dijkstra优化
#pragma warning(disable:4996)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 9999999;

int N, M;
int d[105]; //从源点到第i个点的最短距离
int vis[105]; //标记数组

struct node
{
	int to, length;
	node(int to1, int length1) //结构体初始化
	{
		to = to1;
		length = length1;
	}
	friend bool operator < (struct node a,struct node b) 
	{
		return a.length > b.length;
	}
};

vector<node> v[105];

void dijkstra()
{
	int i;
	memset(d, maxn, sizeof(d));
	memset(vis, 0, sizeof(vis));
	priority_queue<node> q;
	d[1] = 0;
	q.push(node(1, 0));
	while (q.empty() != 1)
	{
		node t = q.top();
		q.pop();
		int pos = t.to; //pos表示目前到源点最短距离的点
		if (vis[pos])
			continue;
		vis[pos] = 1;
		for (i = 0; i < v[pos].size(); i++)
		{
			node x = v[pos][i]; //表示以pos为起点，可以到达的其他的点x.to
			//如果x.to没有进过队列，并且通过pos可以将源点到x.to的距离缩短
			if (!vis[x.to] && d[x.to] > d[pos] + x.length) 
			{
				//更新权值
				d[x.to] = d[pos] + x.length;
				//每更新依次权值都加入优先队列，可能会重复加入，所以才有前面的if，continue判断。
				q.push(node(x.to, d[x.to]));
			}
		}
	}
}

int main()
{
	int i, a, b, c;
	while (scanf("%d%d", &N, &M) != EOF)
	{
		if (N == 0 && M == 0)
		{
			return 0;
		}
		for (i = 0; i < 105; i++)
		{
			v[i].clear();
		}
		for (i = 0; i < M; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			v[a].push_back(node(b,c));
			v[b].push_back(node(a,c));
		}
		dijkstra();
		printf("%d\n", d[N]);
	}
	return 0;
}
