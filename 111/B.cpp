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
#define X first.first
#define Y first.second
#define Z second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

const int MAXa = 100000 + 9999;

int n;
vi d[MAXa];
int a[MAXa];

int main()
{
	for (int i = 1; i < MAXa; i++)
		for (int j = i; j < MAXa; j += i)
			d[j].pb (i);

	cin >> n;
	rep (i, n)
	{
		int x, y, r = 0;
		cin >> x >> y;
		vi &v = d[x];
		rep (j, sz(v))
			r += a[v[j]] <= i - y, a[v[j]] = i + 1;
		cout << r << endl;
	}
	{ int _; cin >> _; }
}
