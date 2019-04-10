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

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m;
int a[22][22];

inline bool inside(int x, int y) {
	return 0 <= x && 0 <= y && x < n && y < m;
}

int tot;

pair<pii, int> go(int x, int y, int d) {
	d ^= a[x][y];
	tot++;
	if(inside(x + dx[d], y + dy[d]))
		return go(x + dx[d], y + dy[d], d);
	return {pii(x, y), d};
}

bool check(int x, int y, int d) {
	auto tmp = go(x, y, d);
	pii p = tmp.X;
	int dd = tmp.Y;
	if(p.X == x && p.Y == y) return true;
	return abs(p.X - x) + abs(p.Y - y) == 1 && dd == (d ^ 2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;

	int ans = 0;
	ll r = 0;
	rep(i, n * m - 2) r += (rand() % 2) << i;
	for(ll mask = r; mask < (1LL << (n * m)); mask++) {
		rep(i, n) rep(j, m) a[i][j] = (mask >> (i * m + j) & 1) * 2 + 1;
		bool ok = true;
		tot = 0;
		rep(i, n) { ok &= check(i, 0, 0); if(!ok) break; }
		rep(i, n) { ok &= check(i, m-1, 2); if(!ok) break; }
		rep(i, m) { ok &= check(0, i, 1); if(!ok) break; }
		rep(i, m) { ok &= check(n-1, i, 3); if(!ok) break; }

		if(ok && tot == 4 * n * m) {
			rep(i, n) {
				rep(j, m) cout << (a[i][j] == 3 ? '/' : '\\');
				cout << endl;
			}
			cout << " ~~~~~~~~" << endl;
			return 0;
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}

