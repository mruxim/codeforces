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

const int maxn = 100 + 10;

int n, k;
map<vector<int>, double> m;

void go(vector<int> a, int r, double p) {
	if(r == 0) {
		m[a] += p;
		return;
	}
	rep(j, n+1) rep(i, j) {
		reverse(a.begin() + i, a.begin() + j);
		go(a, r-1, p / n / (n+1) * 2);
		reverse(a.begin() + i, a.begin() + j);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	go(a, k, 1);

	double ans = 0;
	for(auto p : m) {
		int cnt = 0;
		rep(j, n) rep(i, j)
			cnt += p.X[i] > p.X[j];
		ans += cnt * p.Y;
	}

	cout.setf(ios::fixed);
	cout.precision(12);
	cout << ans << endl;

	return 0;
}

