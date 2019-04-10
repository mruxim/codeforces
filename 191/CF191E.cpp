// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int((x).size()))
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

const int maxn = 100000 + 1000;
const int ctv = 500;


int n;
ll k;
ll a[maxn], s[maxn];
ll x[maxn];

bool ok (ll v)
{
	int p = 0;
	ll t = 0;
	rep (i, n)
	{
		if (i - p > ctv)
		{
			sort (x + p, x + i);
			inplace_merge (x, x + p, x + i);
			p = i;
		}
		t += lower_bound (x, x + p, s[i] - v) - x;
		fer (j, p, i)
			if (s[i] - s[j] > v) t++;
		if (s[i] > v) t++;
		x[i] = s[i];
	}
	return t >= k;
}

int main()
{
	cin >> n >> k;
	rep (i, n) cin >> a[i];
	rep (i, n) s[i] = (i ? s[i-1] : 0ll) + a[i];

	ll lo = 0, hi = 0;
	rep (i, n)
		if (a[i] < 0) lo += a[i];
		else hi += a[i];

	lo--;

	while (lo + 1 < hi)
		if (ok ((lo + hi)/2)) lo = (lo + hi) / 2;
		else i = (lo + hi) / 2;

	cout << hi << endl;

	{ int _; cin >> _; }
}
