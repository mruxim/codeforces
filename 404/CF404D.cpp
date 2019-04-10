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

const int mod = 1000000000 + 7;
const int maxn = 1000000 + 100;

int n;
string s;
int dp[maxn][3];

int main() {
	ios_base::sync_with_stdio (false);

	cin >> s;
	if(isdigit(s.front())) s.front()++;
	if(isdigit(s.back())) s.back()++;

	s = '*' + s + '*';
	n = sz(s);

	dp[1][2] = 1;

	fer(i, 2, n+1) {
		char c = s[i-1];
		char p = s[i-2];
		if(c == '*' || c == '?') {
			dp[i][2] = dp[i-1][2];
			if(p == '2' || p == '?') dp[i][2] = (dp[i][2] + dp[i-1][1]) % mod;
			if(p == '1' || p == '?') dp[i][2] = (dp[i][2] + dp[i-1][0]) % mod;
		}
		if(isdigit(c) || c == '?') {
			dp[i][1] = dp[i-1][2];
			if(p == '1' || p == '?') dp[i][0] = (dp[i][0] + dp[i-1][1]) % mod;
			if(p == '0' || p == '?') dp[i][0] = (dp[i][0] + dp[i-1][0]) % mod;
		}
	}

	cout << (dp[n][0] + (ll)dp[n][1] + dp[n][2]) % mod << endl;

	{ return 0; }
}

