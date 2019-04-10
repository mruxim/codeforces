// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <bitset>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define mkp make_pair
#define all(X) (X).begin(),(X).end()

#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100 + 10;

int n, m, p;
string s, t, v;

int f[maxn][26];
int dp[maxn][maxn][maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> s >> t >> v;

	n = sz(s);
	m = sz(t);
	p = sz(v);

	rep (k, p)
	{
		string tmp = v.substr (0, k);
		tmp.push_back (' ');	
		rep (ch, 26)
		{
			tmp.back() = ch + 'A';
			rof (nk, sz(tmp)+1, 0) if (equal (v.begin(), v.begin() + nk, tmp.end() - nk))
			{
				f[k][ch] = nk;
				break;
			}
		}
	}

	memset (dp, -50, sizeof dp);
	dp[0][0][0] = 0;

	fer (i, 0, n+1) fer (j, 0, m+1) fer (k, 0, p)
	{
		if (i) dp[i][j][k] = max (dp[i][j][k], dp[i-1][j][k]);
		if (j) dp[i][j][k] = max (dp[i][j][k], dp[i][j-1][k]);
		if (dp[i][j][k] < 0 || i == n || j == m) continue;
		if (s[i] == t[j])
		{
			int kk = f[k][s[i] - 'A'];
			dp[i+1][j+1][kk] = max (dp[i+1][j+1][kk], dp[i][j][k] + 1);
		}
	}

	string ans;
	int i = n, j = m, k = max_element (dp[i][j], dp[i][j]+p) - dp[i][j];
	while (i || j)
	{
		if (i && dp[i][j][k] == dp[i-1][j][k]) { i--; continue; }
		if (j && dp[i][j][k] == dp[i][j-1][k]) { j--; continue; }
		rep (ok, p)
			if (k == f[ok][s[i-1] - 'A'] && dp[i][j][k] == dp[i-1][j-1][ok] + 1)
			{
				i--, j--, k = ok;
				ans += s[i];
				break;
			}
	}

	reverse (all (ans));

	if (sz(ans))
		cout << ans << endl;
	else
		cout << 0 << endl;

	{ int _; cin >> _; return 0; }
}
