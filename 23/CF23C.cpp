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
typedef pair <pii, int> tri;
typedef vector <int> vi;

////////////////////////////////////////////////

const int MAXn = 100000 + 100;

int n;
tri a[2*MAXn];

int main()
{
	int t;
	for (cin >> t; t--; )
	{
		cin >> n;
		rep (i, n*2-1) cin >> a[i].X >> a[i].Y, a[i].Z = i+1;
		sort (a, a+2*n-1);

		cout << "YES" << endl;
		cout << a[2*n-2].Z;
		rep (i, n-1) cout << ' ' << (a[2*i].Y > a[2*i+1].Y ? a[2*i].Z : a[2*i+1].Z);
		cout << endl;
	}
	{ int _; cin >> _; }
}
