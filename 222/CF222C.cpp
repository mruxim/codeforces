// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?

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
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxl = 10000000 + 100;
const int maxn = 100000 + 100;

int n, m;
int a[maxn], b[maxn];

bool ip[maxl];
vector<int> p;
vector<int> c;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];

	fer(i, 2, 10000) if(!ip[i])
		for(int j = i * i; j < maxl; j += i)
			ip[j] = true;

	fer(i, 2, maxl) if(!ip[i]) p.pb(i);

	c.resize(sz(p));

	rep(i, n) {
		rep(j, sz(p)) {
			if(p[j] * p[j] > a[i]) break;
			while(a[i] % p[j] == 0) a[i] /= p[j], c[j]++;
		}
		if(a[i] > 1) c[lower_bound(all(p), a[i]) - p.begin()]++;
	}

	rep(i, n) {
		rep(j, sz(p)) {
			if(p[j] * p[j] > b[i]) break;
			while(b[i] % p[j] == 0) b[i] /= p[j], c[j]--;
		}
		if(b[i] > 1) c[lower_bound(all(p), b[i]) - p.begin()]--;
	}

	vector<int> x, y;

	int num = 1, den = 1;
	rep(i, sz(p)) {
		while(c[i] != 0) {
			if(c[i] > 0) {
				if(maxl / num >= p[i]) num *= p[i], c[i]--;
				else x.pb(num), num = 1;
			} else {
				if(maxl / den >= p[i]) den *= p[i], c[i]++;
				else y.pb(den), den = 1;
			}
		}
	}
	if(num > 1) x.pb(num);
	if(den > 1) y.pb(den);

	if(sz(x) == 0) x.pb(1);
	if(sz(y) == 0) y.pb(1);

	cout << sz(x) << ' ' << sz(y) << endl;
	rep(i, sz(x)) cout << (i ? " " : "") << x[i]; cout << endl;
	rep(i, sz(y)) cout << (i ? " " : "") << y[i]; cout << endl;

	return 0;
}

