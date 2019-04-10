// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?
// ....... .. .... .. ...., ....... ..!

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
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int mod = 1000000000 + 7;
const int maxn = 50 + 10;

int dp[maxn][maxn];
int w[maxn][maxn][maxn];

void addto(int &x, int y) {
	x += y;
	if(x >= mod) x -= mod;
}

int get(int i, int j, int k) {
	if(w[i][j][k] != -1) return w[i][j][k];
	w[i][j][k] = 0;
	rep(x, j+1) rep(y, j-x+1) rep(t, min(x
		w[i][j][k] += get(i-1, j-x-y, k - min(x, y))
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	memset(w, -1, sizeof w);

	int n, m;
	cin >> n >> m; m--;

	dp[0][0] = 1;
	fer(i, 1, n+1) {
		fer(j, 1, i+1) {

			w[j][i-j][k] = w[j-1][][k - x]

			rep(k, (i-j)/2+1)
				addto(dp[i][j + k], w[j][i-j][k]);
		}
	}

	cout << dp[n][m] << endl;

	return 0;
}

