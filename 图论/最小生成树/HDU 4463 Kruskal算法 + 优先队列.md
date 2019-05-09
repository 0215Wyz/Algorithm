# HDU 4463 Kruskal算法 + 优先队列
【问题描述】<br>
In China, foreign brand commodities are often much more expensive than abroad. The main reason is that we Chinese people tend to think foreign things are better and we are willing to pay much for them. The typical example is, on the United Airline flight, they give you Haagendazs ice cream for free, but in China, you will pay $10 to buy just a little cup.<br>
So when we Chinese go abroad, one of our most favorite activities is shopping in outlets. Some people buy tens of famous brand shoes and bags one time. In Las Vegas, the existing outlets can't match the demand of Chinese. So they want to build a new outlets in the desert. The new outlets consists of many stores. All stores are connected by roads. They want to minimize the total road length. The owner of the outlets just hired a data mining expert, and the expert told him that Nike store and Apple store must be directly connected by a road. Now please help him figure out how to minimize the total road length under this condition. A store can be considered as a point and a road is a line segment connecting two stores.<br>
【输入描述】<br>
There are several test cases. For each test case: The first line is an integer N( 3 <= N <= 50) , meaning there are N stores in the outlets. These N stores are numbered from 1 to N. The second line contains two integers p and q, indicating that the No. p store is a Nike store and the No. q store is an Apple store. Then N lines follow. The i-th line describes the position of the i-th store. The store position is represented by two integers x,y( -100<= x,y <= 100) , meaning that the coordinate of the store is (x,y). These N stores are all located at different place. The input ends by N = 0.<br>
【输出描述】<br>
For each test case, print the minimum total road length. The result should be rounded to 2 digits after decimal point.<br>
【样例输入】<br>
> 4<br>
> 2 3<br>
> 0 0<br>
> 1 0<br>
> 0 -1 <br>
> 1 -1<br>
> 0<br>

【样例输出】<br>
> 3.41

**注意：**
1. 可以使用结构体＋sort，优先队列是可以直接自动排序的（在写好重载函数的前提下）
2. 使用两个结构体，一个储储存坐标，另一个储存边的信息
3. 这个题的特殊地方在于p和q是已经连通的了，所以在处理优先队列里面的元素之前需要先将p和q连接在一起，即使用join()函数。

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int n, p, q;
int pre[55];
int ran[55];
double x[55];
double y[55];

struct node
{
	int x;
	int y;
	node()
	{
		x = 0;
		y = 0;
	}
};
node N[55];

double dis(node n1, node n2)
{
	return sqrt((n1.x - n2.x)*(n1.x - n2.x) + (n1.y - n2.y)*(n1.y - n2.y));
}

struct edge
{
	int from;
	int to;
	double dis;
	edge(int f, int t, double d) :from(f), to(t), dis(d) {};
	friend bool operator < (struct edge a, struct edge b)
	{
		return a.dis > b.dis;
	}
};

priority_queue<edge> pq;


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
	return true;
}


int main()
{
	int  i, j;
	double ans;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			return 0;
		while (pq.empty() != 1)
		{
			pq.pop();
		}
		init();
		scanf("%d%d", &p, &q);
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d", &N[i].x, &N[i].y);
		}
		for (i = 1; i <= n; i++)
		{
			for (j = i + 1; j <= n; j++)
			{
				pq.push(edge(i, j, dis(N[i], N[j])));
			}
		}
		join(p, q);
		ans = dis(N[p], N[q]);
		while (pq.empty() != 1)
		{
			int x = pq.top().from;
			int y = pq.top().to;
			double s = pq.top().dis;
			pq.pop();
			if (join(x, y))
				ans += s;
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
```

下面是使用结构体＋sort的AC代码，有一点小区别，算法一样。<br>
```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int n, p, q;
int pre[55];
int ran[55];
double x[55];
double y[55];

struct node
{
	int x;
	int y;
	node()
	{
		x = 0;
		y = 0;
	}
};
node N[55];

double dis(node n1, node n2)
{
	return sqrt((n1.x - n2.x)*(n1.x - n2.x) + (n1.y - n2.y)*(n1.y - n2.y));
}

struct edge
{
	int from;
	int to;
	double dis;
};
edge edges[2505];

bool cmp(edge a, edge b)
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
	return true;
}


int main()
{
	int  i, j, tot;
	double ans;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			return 0;
		init();
		tot = 0;
		scanf("%d%d", &p, &q);
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d", &N[i].x, &N[i].y);
		}
		for (i = 1; i <= n; i++)
		{
			for (j = i + 1; j <= n; j++)
			{
				edges[tot].from = i;
				edges[tot].to = j;
				edges[tot++].dis = dis(N[i], N[j]);
			}
		}
		join(p, q);
		ans = dis(N[p], N[q]);
		sort(edges, edges + tot, cmp);
		for (i = 0; i < tot; i++)
		{
			int x = edges[i].from;
			int y = edges[i].to;
			if (join(x, y))
				ans += edges[i].dis;
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
```