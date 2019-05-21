# HDU 5695 Gym Class
【问题描述】<br>
众所周知，度度熊喜欢各类体育活动。 <br>
今天，它终于当上了梦寐以求的体育课老师。第一次课上，它发现一个有趣的事情。在上课之前，所有同学要排成一列， 假设最开始每个人有一个唯一的ID，从1到N，在排好队之后，每个同学会找出包括自己在内的前方所有同学的最小ID，作为自己评价这堂课的分数。麻烦的是，有一些同学不希望某个（些）同学排在他（她）前面，在满足这个前提的情况下，新晋体育课老师——度度熊，希望最后的排队结果可以使得所有同学的评价分数和最大。<br>
【输入描述】<br>
第一行一个整数T，表示T(1≤T≤30) 组数据。 <br>
对于每组数据，第一行输入两个整数N和M(1≤N≤100000,0≤M≤100000)，分别表示总人数和某些同学的偏好。<br> 
接下来M行，每行两个整数A 和B(1≤A,B≤N)，表示ID为A的同学不希望ID为B的同学排在他（她）之前。你可以认为题目保证至少有一种排列方法是符合所有要求的。<br>
【输出描述】<br>
对于每组数据，输出最大分数 。<br>
【样例输入】<br>
> 3<br>
> 1 0<br>
> 2 1<br>
> 1 2<br>
> 3 1<br>
> 3 1<br>

【样例输出】<br>
> 1<br>
> 2<br>
> 6<br>

**注意：**<br>
拓扑排序问题，只是多了几个条件，一个是有的人的站位是受到限制的，另一个就是加到sum里的是包括当前序号在内的前面的一系列数的最小值。所以要设置一个变量记录当前的最小值是多少，如果出现更小的则进行更新，没有的话，就一直将这个最小值加入sum中。<br>


```cpp
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll maxn = 100005;

ll n,m;
ll in[maxn]; 
vector<ll> v[maxn];

int main ()
{
	ll i,j,a,b,T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<=n;i++)
		{
			in[i] = 0;
			v[i].clear();
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&a,&b);//a在b前面 
			v[a].push_back(b);
			in[b]++; 
		}
		priority_queue<ll,vector<ll>,less<ll> > q;
		for(i=1;i<=n;i++)
		{
			if(in[i]==0)
			{
				q.push(i);
			}
		}
		ll ans=0;
		ll min = 999999999;
		while(q.empty()!=1)
		{
			ll t = q.top();
			if(t < min)
			{
				min = t;
			}
			q.pop();
			ans += min;
			for(i=0;i<v[t].size();i++)
			{
				ll x = v[t][i];
				in[x]--;
				if(in[x]==0)
				{
					q.push(x);
				}
			}
		}
		printf("%lld\n",ans);		
	}
	return 0;
}
```