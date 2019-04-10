// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i < _n; i++)
#define rof(i, n, x) for (int i = (n), _x = (x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define cmx(a, b) (a = max(a,b))
#define cmn(a, b) (a = min(a,b))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

const ll MOD = 1000*1000*1000+7;

const int MAXn = 1000 + 9;
const int MAXk = 1000*1000 + 999;

int n, m, k;
ll d[MAXn][MAXn];
ll r[MAXk], f[MAXk], rf[MAXk];

ll pm (ll a, int b)
{
	ll res = 1, tmp = a;
	for (int i = 0; b; tmp *= tmp, tmp %= MOD, b &= ~(1<<i), i++)
		if (b & 1 << i)
			res = res * tmp % MOD;
	return res;
//	if (b == 0) return 1 % MOD;
//	ll tt = pm (a, b/2); tt *= tt;
//	if (b % 2) return tt % MOD * a % MOD;
//	return tt % MOD;
}

void init ()
{
//	int TIME = clock();
	d[0][0] = 1;
	fer (i, 1, MAXn) fer (j, 1, i+1)
		d[i][j] = d[i-1][j-1] + d[i-1][j] * j, d[i][j] %= MOD;
	f[0] = 1;
	fer (i, 1, MAXk) f[i] = f[i-1] * i % MOD;
	fer (i, 1, MAXk) r[i] = pm (i, MOD-2);
	rf[0] = 1;
	fer (i, 1, MAXk) rf[i] = rf[i-1] * r[i] % MOD;
//	cerr << clock() - TIME << endl;
}

ll C (int a, int b)
{
	if (a < 0 || a > b || b < 0) return 0;
	return f[b] * rf[a] % MOD * rf[b-a] % MOD;
}

int main()
{
	init();

	cin >> n >> m >> k;

	ll ans = 0;

	if (m == 1)
		ans = pm (k, n);
	else
		for (int i = 0; i <= n && i <= k; i++) // i common
		{
			ll x = C (i, k) * pm (i, n*(m-2)) % MOD;
			ll y = 0;
			for (int j = 0; i+j <= n && i+j+j <= k; j++) // j new
			{
				y += (d[n][i+j] * f[i+j] % MOD * C (j, k-i) % MOD) * (d[n][i+j] * f[i+j] % MOD * C (j, k-i-j) % MOD) % MOD;
				y %= MOD;
			}
			ans = ans + (x * y) % MOD;
			ans %= MOD;
		}

	cout << ans << endl;
	{ int _; cin >> _; }
}
