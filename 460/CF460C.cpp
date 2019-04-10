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

const int maxn = 100000 + 100;

int n, m, w;
int a[maxn];
int c[2*maxn];

bool check(int h) {
	memset(c, 0, sizeof c);
	int add = 0;
	int used = 0;
	rep(i, n) {
		add += c[i];
		int now = max(0, h - (a[i] + add));
		used += now;
		add += now, c[i+w] -= now;
		if(used > m) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> w;
	rep(i, n) cin >> a[i];

	int lo = 1, hi = 1e9 + 1e6;
	while(hi - lo > 1) {
		int md = (lo + hi) / 2;
		if(check(md)) lo = md;
		else hi = md;
	}

	cout << lo << endl;

	return 0;
}

