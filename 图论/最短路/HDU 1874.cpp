#pragma warning(disable:4996)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

const int maxn1 = 205;
const int maxn2 = 10005;

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

int n, m, s, e;
int d[maxn1];
int vis[maxn1];
vector<node> v[maxn1];

void dijkstra()
{
    int i;
    priority_queue<node> q;
    fill(d, d + maxn1, maxn2);
    memset(vis, 0, sizeof(vis));
    fill(d, d + maxn1, maxn2);
    d[s] = 0;
    q.push(node(s, 0));
    while (q.empty()!= 1)
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
    int i, a, b, c;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        //初始化
        for (i = 0; i <= n; i++)
        {
            v[i].clear();
        }
        //建立连接
        for (i = 0; i < m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            v[b].push_back(node(a, c));
            v[a].push_back(node(b, c));
        }
        //输入起点和终点
        scanf("%d%d", &s, &e);
        
        //Dijkstra算法
        dijkstra();

        if (d[e] == maxn2)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", d[e]);
        }
    }
    return 0;
}
