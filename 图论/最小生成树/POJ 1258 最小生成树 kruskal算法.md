# POJ 1258 最小生成树 kruskal算法 

【问题描述】<br>

Farmer John has been elected mayor of his town! One of his campaign promises was to bring internet connectivity to all farms in the area. He needs your help, of course. <br>
Farmer John ordered a high speed connection for his farm and is going to share his connectivity with the other farmers. To minimize cost, he wants to lay the minimum amount of optical fiber to connect his farm to all the other farms.<br>
Given a list of how much fiber it takes to connect each pair of farms, you must find the minimum amount of fiber needed to connect them all together. Each farm must connect to some other farm such that a packet can flow from any one farm to any other farm. <br>
The distance between any two farms will not exceed 100,000. <br>

【输入描述】<br>

The input includes several cases. For each case, the first line contains the number of farms, N (3 <= N <= 100). The following lines contain the N x N conectivity matrix, where each element shows the distance from on farm to another. Logically, they are N lines of N space-separated integers. Physically, they are limited in length to 80 characters, so some lines continue onto others. Of course, the diagonal will be 0, since the distance from farm i to itself is not interesting for this problem.<br>

【输出描述】<br>

For each case, output a single integer length that is the sum of the minimum length of fiber required to connect the entire set of farms.<br>

【样例输入】<br>
> 4<br>
> 0 4 9 21<br>
> 4 0 8 17<br>
> 9 8 0 16<br>
> 21 17 16 0<br>

【样例输出】<br>
> 28

**注意：**<br>

这个使用的是并查集，和Prim算法不同的是，Prim算法是从一个指定的点开始生成最小生成树，kruskal算法则是在所有的边集合种选择最小的边作为起始边。

1. ran数组用来记录形成的数的深度，用于合并
2. pre数组记录每一个结点的父节点的序号，当它的父结点是它本身的时候，他就是根结点
3. 结构体数组一开始只是开到205，一直是RE状态，后来才明白过来，N的范围是\[3，100\]，所以最小也得开到10000（100*100）



```cpp
#pragma warning(disable:4996)

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 105;

int n;
int tot;
int pre[maxn];
int ran[maxn];

struct node
{
	int from;
	int to;
	int dis;
};

node edge[10000+10];

bool cmp(node a, node b)
{
	return a.dis < b.dis;
}

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
	if (pre[x] == x)
		return x;
	return pre[x] = find(pre[x]);
}

void join(int x, int y)
{
	int a = find(x);
	int b = find(y);
	if (a == b)
		return;
	if (ran[a] > ran[b])
	{
		pre[b] = a;
	}
	else
	{
		if (ran[a] == ran[b])
		{
			ran[b]++;
		}
		pre[a] = b;
	}
}


int main()
{
	int i, j, k, ans;
	while (scanf("%d", &n) != EOF)
	{
		init();
		tot = 0;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				edge[tot].from = i;
				edge[tot].to = j;
				scanf("%d", &edge[tot++].dis);
			}
		}
		sort(edge, edge + tot, cmp);
		k = 0;
		ans = 0;
		for (i = 0; i < tot; i++)
		{
			if (k == n - 1)
				break;
			if (find(edge[i].from) != find(edge[i].to))
			{
				join(edge[i].from, edge[i].to);
				ans += edge[i].dis;
				k++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
```