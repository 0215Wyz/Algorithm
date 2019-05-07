#pragma warning(disable:4996)

#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 105;
const int inf = 0x3f3f3f3f;

int n, ans;
int map[maxn][maxn];//邻接矩阵
int d[maxn];//距离向量
int vis[maxn];//标记数组

void prim()
{
	int i, j, min, pos;
	d[0] = 0;
	for (i = 1; i <= n; i++)
	{
		d[i] = map[1][i];
	}
	fill(vis, vis + maxn, 0);
	vis[1] = 0;
	for (i = 1; i < n; i++)
	{
		min = inf;
		for (j = 2; j <= n; j++)
		{
			if (!vis[j] && min > d[j])
			{
				min = d[j];
				pos = j;
			}
		}
		if (min == inf)
			return;
		vis[pos] = 1;
		ans += min;
		for (j = 2; j <= n; j++)
		{
			if (!vis[j] && d[j] > map[pos][j])
			{
				d[j] = map[pos][j];
			}
		}
	}
}

int main()
{
	int i, j;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		ans = 0;
		prim();
		printf("%d\n", ans);
	}
	return 0;
}