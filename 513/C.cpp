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

const int maxn = 5 + 2;
const int maxv = 10000 + 100;

int n;
int a[maxn], b[maxn];
long double s[maxn][maxv];

inline long double get(int i, int l, int r = -1) {
	if(r == -1) r = l+1;
	smin(r, maxv-1);
	return s[i][r] - s[i][l];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) {
		cin >> a[i] >> b[i], b[i]++;
		long double pr = 1.0 / (b[i] - a[i]);
		fer(v, 1, maxv)
			s[i][v] = s[i][v-1] + (a[i] <= v-1 && v-1 < b[i] ? pr : 0.0);
	}

	long double ans = 0;

	rep(v, maxv) rep(i, n) if(a[i] <= v && v <= b[i]) {
		rep(j, n) if(j != i) {
			long double prob = get(i, v) * get(j, v + (j < i ? 1 : 0), maxv);
			rep(k, n) if(k != i && k != j)
				prob *= get(k, 0, v + (k < i ? 1 : 0));
			ans += prob * v;
		}
	}

	cout.setf(ios::fixed);
	cout.precision(12);
	cout << ans << endl;

	return 0;
}

