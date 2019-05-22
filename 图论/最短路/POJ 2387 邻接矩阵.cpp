#include <iostream>
#include <cstdio>
 
using namespace std;

const int maxn = 1005; 
const int inf = 99999999;
int map[maxn][maxn];
int d[maxn];
int vis[maxn];
int n,m;

void init()
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		d[i] = 0;
		vis[i] = 0;
		for(j=0;j<=n;j++)
		{
			if(i==j)
				map[i][j] = 0;
			else
				map[i][j] = inf; 
		} 
	}
}

void dijkstra()
{
	int i,j;
	int min,pos;
	for(i=0;i<n;i++)
	{
		min = inf;
		for(j=1;j<n;j++)
		{
			if(!vis[j] && min>d[j])
			{
				min = d[j];
				pos = j;
			}
		}
		if(min==inf)
			return ;
		vis[pos] = 1;
		for(j=1;j<n;j++)
		{
			if(!vis[j] && d[j]>min+map[pos][j])
			{
				d[j] = min + map[pos][j];
			}
		}
	}
}

int main ()
{
	int i,a,b,c;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		init();
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(map[a][b]>c)
			{
				map[a][b] = c;
				map[b][a] = c;
			}
		}
		for(i=1;i<=n;i++)
		{
			d[i] = map[n][i];
		}
		vis[n] = 1;
		dijkstra();
		printf("%d\n",d[1]);
	}
	return 0;
} 