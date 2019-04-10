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

const int MAXn = 1000 * 1000;
const int MAXb = 22;

int n;
int a[MAXn];
int r[1<<MAXb];

int main()
{
	memset (r, -1, sizeof r);
	cin >> n;
	rep (i, n) cin >> a[i], r[a[i]] = a[i];
	rep (i, 1<<MAXb)
	{
		if (r[i] > 0) continue;
		for (int t = i, z; t; t ^= z)
		{
			z = t & -t;
			r[i] = r[i^z];
			if (r[i] > 0) break;
		}
	}
	rep (i, n)
		cout << r[( (~a[i])&((1<<MAXb)-1) )] << ' ';
	cout << endl;
//	rep (i, 100)
//		cout << r[( (~i)&((1<<MAXb)-1) )] << endl;
	{ int _; cin >> _; }
}
