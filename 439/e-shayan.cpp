#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <ctime>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define VAL(x) #x << " = " << (x) << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second
#define EPS (1e-8)

//#define cin fin
//#define cout fout

//ifstream fin("problem.in");
//ofstream fout("problem.out");

const int MAXN = 100 * 1000 + 10, MOD = 1e9 + 7;

map<int, ll> dp[MAXN];
map<int, bool> seen[MAXN];

ll binPow(ll n, ll a)
{
	if (a == 0) return 1;

	if (a & 1)
	{
		ll t = binPow(n, a - 1);
		return (t * n) % MOD;
	}
	else
	{
		ll t = binPow(n, a / 2);
		return SQR(t) % MOD;
	}
}

ll fa[MAXN], rev[MAXN], revf[MAXN];

void preprocess(ll n)
{
	fa[0] = 1ll;
	for (ll i = 1; i <= n; i ++)
		fa[i] = (fa[i - 1] * i) % MOD;

	for (int i = 1; i <= n; i ++)
		rev[i] = binPow((ll)i, MOD - 2);

	rev[0] = rev[1];
	revf[0] = rev[0];
	for (int i = 1; i <= n; i ++)
		revf[i] = (rev[i] * revf[i - 1]) % MOD;
}

ll C(ll n, ll r)
{
	if (r == 0 || r == n) return 1;
	return (((fa[n] * revf[r]) % MOD) * revf[n - r]) % MOD;
}

vector<int> dv[MAXN];

ll f(int n, int k)
{
	if (n == k) return 1;
	if (n < k) return 0;
	if (n == 0) return 0;
	if (n == 1) return k;

	if (seen[n][k]) return dp[n][k];

	ll res = C(n - 1, k - 1);
	for (int i = 0; i < SZ(dv[n]); i ++) 
		res = (res - f(n / dv[n][i], k) + MOD) % MOD;
	seen[n][k] = true; dp[n][k] = res;

	return res;
}

int main ()
{
	ios::sync_with_stdio(false);

	for (int i = 2; i < MAXN; i ++)
		for (int j = i; j < MAXN; j += i)
			dv[j].pb(i);
	preprocess(MAXN);
	
	int q;
//	cin >> q;
	q = 100000;
	while (q --)
	{
		int n, k;
		n = 60060, k = 1;
	//	cin >> n >> k;
		cout << f(n, k) << endl;
	}
	return 0;
}
