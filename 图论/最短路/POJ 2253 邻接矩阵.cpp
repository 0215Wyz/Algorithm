/*
最短路变形 找的是1-2的所有路径中某一小段中的最大值，然后找这些最大值中的最小值 
*/ 

#pragma warning(disable:4996)

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 205;
const double inf = 9999999999.0;

int n;
double map[maxn][maxn];
double d[maxn];
int vis[maxn];
double x[maxn];
double y[maxn];

void dijkstra()
{
	int i, j, pos;
	double minn;
	fill(d, d + maxn, inf);
	fill(vis, vis + maxn, 0);
	for (i = 1; i <= n; i++)
	{
		d[i] = map[1][i];
	}
	d[1] = 0;
	vis[1] = 1;
	for (i = 1; i < n; i++)
	{
		minn = inf;
		for (j = 2; j <= n; j++)
		{
			if (!vis[j] && minn > d[j])
			{
				minn = d[j];
				pos = j;
			}
		}
		if (minn == inf)
			return;
		vis[pos] = 1;
		for (j = 2; j <= n; j++)
		{
			d[j] = min(d[j], max(d[pos], map[pos][j]));
		}
	}
}

int main()
{
	int i, j, cnt = 1;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			return 0;
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				if (i == j)
					map[i][j] = 0;
				else
					map[i][j] = inf;
			}
		}
		for (i = 1; i <= n; i++)
		{
			scanf("%lf%lf", &x[i], &y[i]);
		}
		for (i = 1; i <= n; i++)
		{
			for (j = i + 1; j <= n; j++)
			{
				map[i][j] = map[j][i] = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
			}
		}

		dijkstra();
		printf("Scenario #%d\n",(cnt++));
		printf("Frog Distance = %.3lf\n\n", d[2]);
	}
	return 0;
}
