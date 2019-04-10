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

const int MAXn = 100000 + 999;

int n, m;
ll x, y;
ll a[MAXn], b[MAXn];
vector <pii> v;

int main()
{
	cin >> n >> m >> x >> y;
	rep (i, n) cin >> a[i];
	rep (i, m) cin >> b[i];
	sort (a, a+n);
	sort (b, b+m);
	int ans = 0;
	int p = 0, q = 0;
	for (p = 0; p<n && a[p]+y <b[0]; p++);
	for ( ; p<n; p++)
	{
		while (q<m && b[q] < a[p]-x) q++;
		if (q<m && a[p]-x <= b[q] && b[q] <= a[p]+y)
			v.pb (mp (p+1, q+1)), ans++, q++;
	}
	cout << ans << endl;
	rep (i, ans)
		cout << v[i].X << ' ' << v[i].Y << endl;
	{ int _; cin >> _; }
}
