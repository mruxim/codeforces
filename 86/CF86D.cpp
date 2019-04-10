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
#define L first.first
#define R first.second
#define ID second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> tri;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 200000 + 100;
const int ctv = 650;

int n, t;
int a[maxn];
int cnt[1000000+100];
tri q[maxn];
ll ans[maxn];
int curL = 0, curR = 0;
ll curV = 0;

inline void change(int color, int val) {
	curV += color * (ll)(2 * val * cnt[color] + 1);
	cnt[color] += val;
}

int main() {
	cin >> n >> t;
	rep(i, n) scanf("%d", a+i);
	rep(i, t) scanf("%d%d", &q[i].L, &q[i].R), q[i].L--, q[i].ID = i;

	sort(q, q+t, [](tri q1, tri q2) {
				return (q1.L/ctv != q2.L/ctv) ? (q1.L/ctv < q2.L/ctv) : ((q1.L/ctv % 2) ^ (q1.R < q2.R));
			});

	rep(i, t) {
		while(curL > q[i].L) change(a[--curL], 1);
		while(curR < q[i].R) change(a[curR++], 1);
		while(curL < q[i].L) change(a[curL++], -1);
		while(curR > q[i].R) change(a[--curR], -1);
		ans[q[i].ID] = curV;
	}

	rep(i, t) printf("%I64d\n", ans[i]);

	{ return 0; }
}

