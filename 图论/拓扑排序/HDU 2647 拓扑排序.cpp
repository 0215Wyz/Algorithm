#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 10005;

int n,m;
int in[maxn];
int num[maxn];
vector<int> v[maxn];

int main ()
{
	int i,j,a,b;
	queue<int> q;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<=n;i++)
		{
			v[i].clear();
			in[i]=0;
			num[i]=888;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);//a的工资应该比b的高 
			v[b].push_back(a);
			in[a]++;
		}
		for(i=1;i<=n;i++)
		{
			if(in[i]==0)
			{
				q.push(i);
			}
		}
		int sum=0;
		int cnt=0;
		while(q.empty()!=1)
		{
			int t = q.front();
			q.pop();
			cnt++;
			sum += num[t];
			if(cnt==n)
				break;
			for(i=0;i<v[t].size();i++)
			{
				int x = v[t][i];
				in[x]--;
				if(in[x]==0)
				{
					num[x] = num[t]+1;
					q.push(x);
				}
			}
		}
		if(cnt==n)
		{
			printf("%d\n",sum);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
} 
