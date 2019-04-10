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

int n;
ll p[55];
ll a[10], b[10];
ll x;

int main()
{
	cin >> n;
	rep (i, n) cin >> p[i];
	rep (i, 5) cin >> a[i];
	a[6] = (int)1e9 + 1000;
	rep (i, n)
	{
		x += p[i];
		rof (j, 5, 0)
			b[j] += x / a[j],
			x -= x/a[j]*a[j];
	}
	rep (i, 5) cout << b[i] << ' ';
	cout << endl;
	cout << x << endl;
	{ int _; cin >> _; }
}
