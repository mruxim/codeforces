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

const int maxn = 50 + 2;
const int maxm = 20;

int n, m;
string s[maxn];
ll dp[1<<maxm];
ll C[maxn][maxn];

int getand(int p, int q) {
	int res = 0;
	rep(i, m) if(s[p][i] == s[q][i]) res |= 1 << i;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> s[i];
	m = sz(s[0]);

	rep(i, n) rep(j, n) if(i != j) {
		int tmp = getand(i, j);
		dp[tmp] |= 1LL << i;
	}

	rep(bit, m) rep(mask, 1 << m) if(!(mask >> bit & 1))
		dp[mask] |= dp[mask ^ (1 << bit)];

	rep(i, maxn) {
		C[i][0] = C[i][i] = 1;
		fer(j, 1, i) C[i][j] = C[i-1][j] + C[i-1][j-1];
	}

	double ans = 0;
	rep(mask, 1 << m) {
		int cnt = __builtin_popcountll(dp[mask]);
		ans += cnt / (double)C[m][__builtin_popcount(mask)];
	}

	cout.setf(ios::fixed);
	cout.precision(12);
	cout << ans / n << endl;


	return 0;
}

