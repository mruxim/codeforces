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

const int maxn = 2000 + 100;

int n;
int a[maxn], b[maxn];
int p[maxn], w[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i], a[i]--;
	rep(i, n) cin >> b[i], b[i]--;

	rep(i, n) rep(j, n) if(a[i] == b[j]) p[i] = j, w[j] = i;

	int ans = 0;
	vector<pii> v;
	rep(i, n) {
		for(int k = w[i]; k > i; k = w[i]) {
			for(int j = k-1; j >= i; j--)
				if(p[j] >= k) {
					swap(p[j], p[k]), swap(w[p[j]], w[p[k]]);
					ans += k - j;
					v.pb(pii(j, k));
					break;
				}
		}
	}
	cout << ans << endl;
	cout << sz(v) << endl;
	rep(i, sz(v)) cout << v[i].X + 1 << ' ' << v[i].Y + 1 << endl;

	return 0;
}

