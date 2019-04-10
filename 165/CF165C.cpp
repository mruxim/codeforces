// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i < _n; i++)
#define rof(i, n, x) for (int i = (n), _x = (x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define cmx(a, b) (a = max(a,b))
#define cmn(a, b) (a = min(a,b))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

int k;
string s;
vi a;

int main()
{
	cin >> k >> s;
	ll ans = 0;
	a.pb(-1);
	rep (i, sz(s)) if (s[i] == '1') a.pb (i);
	a.pb(sz(s));
	int n = sz(a);
	if (k > 0)
		fer (i, 1, n-k) ans += (ll)(a[i]-a[i-1]) * (a[i+k]-a[i+k-1]);
	else
		fer (i, 1, n) ans += (ll)(a[i]-a[i-1]) * (a[i]-a[i-1]-1) / 2;
	cout << ans << endl;
	{ int _; cin >> _; }
}
