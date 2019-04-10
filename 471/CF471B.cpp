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

const int maxn = 2000 + 100;

int n;
pii p[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> p[i].X, p[i].Y = i;
	sort(p, p+n);

	int cnt = 0;
	rep(i, n-1) {
		if(p[i].X == p[i+1].X) cnt++;
		if(i+2 < n && p[i].X == p[i+2].X) cnt++;
	}

	if(cnt <= 1) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		rep(z, 3) {
			rep(j, n) cout << p[j].Y+1 << ' '; cout << endl;
			if(z == 0)
				rep(i, n-1) {
					if(p[i].X == p[i+1].X) {
						swap(p[i], p[i+1]);
						break;
					}
				}
			else
				rof(i, n-1, 0) {
					if(p[i].X == p[i+1].X) {
						swap(p[i], p[i+1]);
						break;
					}
				}
		}
	}

	return 0;
}

