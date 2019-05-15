#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 505;

int n,m;
int map[maxn][maxn];
int in[maxn];
priority_queue<int,vector<int>,greater<int> > q;

int main ()
{
	int i,j,a,b,cnt,ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(map,0,sizeof(map));
		memset(in,0,sizeof(in));
		while(m--)
		{
			cin >> a >> b;
			if(map[a][b])
				continue;
			map[a][b]=1;
			in[b]++;
		}
		for(i=1;i<=n;i++)
		{
			if(in[i]==0)
			{
				q.push(i);
			}
		} 
		cnt = 0;
		while(q.empty()!=1)
		{
			ans = q.top();
			q.pop();
			if(cnt!=n-1)
			{
				cout << ans << " ";
				cnt++;
				for(i=1;i<=n;i++)
				{
					if(map[ans][i]==0)
						continue;
					in[i]--;
					if(in[i]==0)
					{
						q.push(i);
					}
				}
			}
			else
			{
				cout << ans << endl;
			}
		}
	}
	return 0;
}
