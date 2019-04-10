// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include<bits/stdc++.h>
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

const int maxn = 2000 + 100;

int n;
string s, p;
int dp[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> s; n = sz(s);
	cin >> p;

	fer(i, 1, n+1) {
		int pos = sz(p);
		int k = i;
		while(pos && k) {
			if(p[pos-1] == s[k-1]) pos--;
			k--;
		}
		if(pos == 0) fer(j, sz(p), i+1) if(j - sz(p) <= k) dp[i][j] = dp[k][j-sz(p)] + 1;
		rep(j, i+1) {
			if(j) smax(dp[i][j], dp[i-1][j-1]);
			if(j <= i-1) smax(dp[i][j], dp[i-1][j]);
		}
	}

	rep(i, n+1) cout << dp[n][n-i] << ' ';
	cout << endl;

	return 0;
}

