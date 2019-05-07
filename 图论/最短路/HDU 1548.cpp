#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 205;

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

int n, a, b;
int d[maxn];
int vis[maxn];
vector<node> v[maxn];

void dijkstra()
{
    int i;
    priority_queue<node> q;
    fill(d, d + maxn, maxn);
    fill(vis, vis + maxn, 0);
    d[a] = 0;
    q.push(node(a, 0));
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
            node x = v[pos][i];
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
    int i, x;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            return 0;
        scanf("%d%d", &a, &b);
        for (i = 1; i <= n; i++)
        {
            v[i].clear();
        }
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            if (i + x <= n)
            {
                v[i].push_back(node(i + x, 1));
            }
            if (i - x >= 1)
            {
                v[i].push_back(node(i - x, 1));
            }
        }
        dijkstra();
        if (d[b] != maxn)
            printf("%d\n", d[b]);
        else
            printf("-1\n");
    }
    return 0;
}
