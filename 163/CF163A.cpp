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

const ll mod = 1000000007;
const int MAXn = 5000 + 100;

string s, t;
int n, m;
ll dp[MAXn][MAXn];

int main()
{
	cin >> s >> t;
	n = sz(s), m = sz(t);
	rof (i, n, 0)
	{
		rof (j, m, 0)
		{
			dp[i][j] = dp[i][j+1];
			if (s[i] == t[j]) dp[i][j] += dp[i+1][j+1] + 1;
			if (dp[i][j] >= mod) dp[i][j] -= mod;
		}
	}

	ll res = 0;
	rep (i, n)
		res += dp[i][0], res %= mod;
	cout << res << endl;
	{ int _; cin >> _; }
}
