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

const int mod = 1000000000+7;
const int maxn = 5000 + 10;

int n;
string s;
int val[maxn][maxn];
int cnt[maxn][maxn];
int dis[maxn][maxn];
int dif[maxn][maxn];

void fix(int &x) { while(x < 0) x += mod; if(x >= mod) x -= mod; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> s; n = sz(s);

	rep(j, n+1) rep(i, j)
		val[i][j] = val[i][j-1] * 2 + s[j-1] - '0', fix(val[i][j]);

	rof(i, n, 0) rof(j, n, 0) dif[i][j] = (s[i] == s[j] ? dif[i+1][j+1] + 1 : 0);

	int ans = 0;

	memset(dis, 50, sizeof dis);
	cnt[0][1] = 1;
	dis[0][1] = 1;
	rep(j, n+1) rep(i, j) if(cnt[i][j]) {
		if(j == n) { ans += cnt[i][j]; fix(ans); continue; }

		cnt[i][j+1] += cnt[i][j]; fix(cnt[i][j+1]);
		smin(dis[i][j+1], dis[i][j]);
		if(s[j] == '0') continue;

		int k = j + (j - i), d = dif[i][j];
		if(j+d < min(k, n) && s[i+d] > s[j+d]) k++;
		if(k > n) continue;

		cnt[j][k] += cnt[i][j]; fix(cnt[j][k]);
		smin(dis[j][k], dis[i][j]+1);
	}

	cout << ans << endl;

	int d = mod + mod;
	fer(i, max(0, n-15), n) if(cnt[i][n]) smin(d, dis[i][n] + val[i][n]);

	if(d == mod + mod)
		rep(i, n) if(cnt[i][n]) d = dis[i][n] + val[i][n], fix(d);

	cout << d << endl;

	return 0;
}

