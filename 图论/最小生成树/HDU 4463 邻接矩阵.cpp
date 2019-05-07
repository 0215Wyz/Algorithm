#pragma warning(disable:4996)

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 55;
const double inf = 999999999.0;

int n, p, q;
double x[maxn];
double y[maxn];
double d[maxn];
double map[maxn][maxn];
double ans;
int vis[maxn];

void prim()
{
    int i, j, pos;
    double minn;
    ans += map[p][q];
    for (i = 1; i <= n; i++)
    {
        d[i] = min(map[p][i],map[q][i]);
    }
    fill(vis, vis + maxn, 0);
    vis[p] = 1;
    vis[q] = 1;
    for (i = 1; i <= n-2; i++)
    {
        minn = inf;
        for (j = 1; j <= n; j++)
        {
            if (!vis[j] && minn > d[j])
            {
                minn = d[j];
                pos = j;
            }
        }
        if (minn == inf)
            return;
        ans += minn;
        vis[pos] = 1;
        for (j = 1; j <= n; j++)
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
        if (n == 0)
            return 0;
        scanf("%d%d", &p, &q);
        for (i = 1; i <= n; i++)
        {
            scanf("%lf%lf", &x[i], &y[i]);
        }
        ans = 0;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= i; j++)
            {
                if (i == j)
                    map[i][j] = 0;
                else
                    map[i][j] = map[j][i] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            }
        }
        prim();
        printf("%.2lf\n", ans);
    }
    return 0;
}