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

const int maxn = 200000 + 100;
const int maxd = 160 + 5;

int n;
int a[maxn];
int mx[maxd][maxn];
vector<int> t[maxd];

vector<int> v;

void gen(int x) {
	v.clear();
	for(int i = 1; i*i <= x; i++) if(x % i == 0) {
		v.push_back(i);
		if(i*i < x) v.push_back(x/i);
	}
	sort(all(v));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i];
	
	gen(n);
	rep(j, sz(v)) {
		int imod = 0;
		rep(i, n) {
			smax(mx[j][imod], a[i]);
			if(++imod == v[j]) imod = 0;
		}
	}

	fer(s, 1, n) t[lower_bound(all(v), __gcd(s, n)) - v.begin()].push_back(s);

	ll ans = 0;

	rep(j, sz(v)) {
		int imod = 0;
		int len = 0;
		rep(i, n) {
			if(mx[j][imod] <= a[i]) len++;
			else len = 0;
			if(++imod == v[j]) imod = 0;
		}
		int p = 0;
		rep(i, n) {
			if(mx[j][imod] <= a[i]) len++;
			else len = 0, p = 0;
			while(p < sz(t[j]) && t[j][p] <= len) p++;
			ans += p;
			if(++imod == v[j]) imod = 0;
		}
	}

	cout << ans << endl;

	return 0;
}

