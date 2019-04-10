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

const int maxn = 1000 + 10;

int n;
int a[maxn][5];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) rep(j, 5) cin >> a[i][j];

	if(n > 11) {
		cout << 0 << endl;
		return 0;
	}

	vector<int> good;
	rep(i, n) {
		bool ok = true;
		rep(j, n) rep(k, j) if(j != i && k != i) {
			int s = 0;
			rep(t, 5) s += (a[j][t] - a[i][t]) * (a[k][t] - a[i][t]);
			if(s > 0) ok = false;
		}
		if(ok) good.pb(i);
	}

	cout << good.size() << endl;
	for(int i: good) cout << i + 1 << endl;

	return 0;
}

