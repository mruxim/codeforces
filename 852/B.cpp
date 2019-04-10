// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?
// ....... .. .... .. ...., ....... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for (int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for (int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int mod = 1000000000 + 7;
const int maxn = 1000000 + 100;
const int maxm = 100 + 10;
const int maxlog = 20;

int n, l, m;
int rb[maxm];
int a[maxm], b[maxlog][maxm], c[maxm];
int res[maxm], tmp[maxm];

void addto(int &x, int y) { x += y; if(x >= mod) x -= mod; }

void mul(int p[maxm], int q[maxm], int r[maxm]) {
	rep(i, m) rep(j, m) addto(r[(i + j) % m], p[i] * (ll)q[j] % m);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> l >> m; l -= 2;
	rep(i, n) { int x; cin >> x; a[x % m]++; }
	rep(i, n) { cin >> rb[i]; b[0][rb[i] % m]++; }
	rep(i, n) { int x; cin >> x; c[(rb[i] + x) % m]++; }

	fer(i, 1, maxlog) mul(b[i-1], b[i-1], b[i]);

	copy(a, a + m, res);
	rep(i, maxlog) if(l >> i & 1) {
		copy(res, res + m, tmp);
		memset(res, 0, sizeof res);
		mul(tmp, b[i], res);
	}

	copy(res, res + m, tmp);
	memset(res, 0, sizeof res);
	mul(tmp, c, res);

	cout << res[0] << endl;

	return 0;
}

