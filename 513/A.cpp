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

const int maxn = 50 + 5;

int k1, k2;
char dp[maxn][maxn][2];

bool calc(int n1, int n2, int t) {
	if(dp[n1][n2][t] != -1) return dp[n1][n2][t];

	if(t == 0) {
		fer(i, 1, min(n1, k1) + 1)
			if(calc(n1 - i, n2, 1))
				return (dp[n1][n2][t] = 1);
		return (dp[n1][n2][t] = 0);
	} else {
		fer(i, 1, min(n2, k2) + 1)
			if(!calc(n1, n2 - i, 0))
				return (dp[n1][n2][t] = 0);
		return (dp[n1][n2][t] = 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n1, n2;
	cin >> n1 >> n2 >> k1 >> k2;

	memset(dp, -1, sizeof dp);
	cout << (calc(n1, n2, 0) ? "First" : "Second") << endl;

	return 0;
}

