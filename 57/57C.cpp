#include <iostream>

using namespace std;

const long long MOD = 1000000007;

int n;
long long ans;

long long pm (long long b, int p)
{
	if (p == 1)
		return b;
	long long ret = pm (b, p / 2);
	ret = ret * ret % MOD;
	if (p % 2 == 1)
		ret = ret * b % MOD;
	return ret;
}

int main()
{
	cin >> n;

/**/	ans = 1;
	for (int i = n+1; i < 2*n; i++)
		ans = ans * i % MOD;
	for (int i = 1; i < n; i++)
		ans = ans * pm (i, MOD-2) % MOD;
	ans = ans * 2 - n;/**/
	ans = (ans + MOD) % MOD;
	cout << ans << endl;
	{ int _; cin >> _; }
}
