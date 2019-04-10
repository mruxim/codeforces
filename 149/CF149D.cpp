// .... .... .....!
// P..... C.....!

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

const int mod = 1000000007;
const int maxn = 700 + 50;

int n;
string s;
int match[maxn];
int dp[maxn][maxn][3][3];

inline void fix (int &v) { if (v >= mod) v -= mod; }

void solve (int l, int r)
{
	if (dp[l][r][0][0] != -1) return;

	rep (i, 3) rep (j, 3) dp[l][r][i][j] = 0;

	if (l + 1 == r)
	{
		rep (i, 3) rep (j, 3) dp[l][r][i][j] = (int)(i*j==0 && i+j!=0);
		return;
	}


	if (match[l] == r)
	{
		solve (l+1, r-1);
		rep (i, 3) rep (j, 3) if (i*j==0 && i+j!=0)
			rep (ii, 3) rep (jj, 3) if ((i!=ii||i==0) && (j!=jj||j==0))
				dp[l][r][i][j] += dp[l+1][r-1][ii][jj],
				fix (dp[l][r][i][j]);
		return;
	}

	solve (l, match[l]);
	solve (match[l]+1, r);
	

	rep (i, 3) rep (j, 3) rep (ii, 3) rep (jj, 3)
		if (j != ii || j == 0)
			dp[l][r][i][jj] += dp[l][match[l]][i][j] * (ll)dp[match[l]+1][r][ii][jj] % mod,
			fix (dp[l][r][i][jj]);
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> s; n = sz(s);

	stack<int> st;
	rep (i, n)
	{
		if (s[i] == '(') st.push (i);
		else match[i] = st.top(), match[st.top()] = i, st.pop();
	}

	memset (dp, -1, sizeof dp);

	solve (0, n-1);

	int ans = 0;
	rep (i, 3) rep (j, 3) ans += dp[0][n-1][i][j], fix (ans);

	cout << ans << endl;	

	{ int _; cin >> _; return 0; }
}
