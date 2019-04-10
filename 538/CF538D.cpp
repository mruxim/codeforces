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
#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 50 + 10;

int n;
string s[maxn];
vector<pii> p, v;

bool bad[2*maxn][2*maxn];
string ans[2*maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> s[i];

	rep(i, 2*n-1) ans[i] = string(2*n-1, '.');
	ans[n-1][n-1] = 'o';

	rep(i, n) rep(j, n) if(s[i][j] == 'o') p.pb({i, j});

	rep(i, n) rep(j, n) if(s[i][j] == 'o')
		rep(ii, n) rep(jj, n) if(s[ii][jj] == '.')
			bad[ii - i + maxn][jj - j + maxn] = true;

	rep(i, n) rep(j, n) if(s[i][j] == 'x') {
		bool ok = false;
		rep(r, sz(p)) if(!bad[i - p[r].X + maxn][j - p[r].Y + maxn]) {
			ok = true;
			ans[n - 1 + i - p[r].X][n - 1 + j - p[r].Y] = 'x';
			break;
		}
		if(!ok) { cout << "NO" << endl; return 0; }
	}

	cout << "YES" << endl;
	rep(i, 2*n-1) cout << ans[i] << endl;

	return 0;
}

