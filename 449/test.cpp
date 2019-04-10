// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int n = 4;

int m;
int dp[1<<n];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> m;
	rep (i, m)
	{
		string str; cin >> str;
		int mask = 0;
		for(char ch: str) mask |= 1 << (ch-'a');
		dp[mask]++;
	}

	rep (i, n) rof (mask, 1<<n, 0)
		if (mask >> i & 1) dp[mask] += dp[mask ^ (1<<i)];

	int ans = 0;
	rep (mask, 1<<n) ans ^= (m-dp[mask]) * (m-dp[mask]);

	rep(i, 1<<n) cerr << " ! " << i << ' ' << dp[i] << endl;

	cout << ans << endl;

	{ return 0; }
}
