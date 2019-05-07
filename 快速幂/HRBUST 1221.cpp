#pragma warning(disable:4996)

#include <iostream>

using namespace std;

typedef long long ll;
ll a, b;

ll quick_mod(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
		{
			b--;
			ans = (ans*a) % 10;
		}
		a = (a*a) % 10;
		b >>= 1;
	}
	return ans;
}

int main()
{
	while (scanf("%lld%lld", &a, &b) != EOF)
	{
		cout << quick_mod(a, b) << endl;
	}
	return 0;
}
