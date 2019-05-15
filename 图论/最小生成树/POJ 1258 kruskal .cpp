#include<iostream>
#include<algorithm>
#include <cstdio>
using namespace std;
const int maxi = 105;
struct node 
{
	int a, b, v;
};
node a[10005];
bool cmp(node a,node b)
{
	return a.v < b.v;
}
int f[maxi];
int find(int x)
{
	if (x != f[x])
		return f[x] = find(f[x]);
	return x; 
}
void join(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx!=fy)
	{
		f[fx] = fy;
	}
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int i, j;
		int cnt = 0;
		for (i=1;i<=n;i++)
		{
			f[i] = i;
			for (j=1;j<=n;j++)
			{
				scanf("%d",&a[cnt].v);
				a[cnt].a = i;
				a[cnt].b = j;
				cnt++;

			}
		}
		int sum = 0;
		sort(a,a+cnt,cmp);
		for (i=0;i<cnt;i++)
		{
			if (find(a[i].a) != find(a[i].b))
			{
				join(a[i].a,a[i].b);
				sum += a[i].v;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
