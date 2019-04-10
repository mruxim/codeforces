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

int n;
int x[222], y[222];

int main()
{
	cin >> n;
	rep (i, n) cin >> x[i] >> y[i];
	int ans = 0;
	rep (i, n)
	{
		int h = 0;
		rep (j, n)
		{
			if (x[i] == x[j] && y[i] < y[j]) h |= 1;
			if (x[i] == x[j] && y[i] > y[j]) h |= 2;
			if (x[i] < x[j] && y[i] == y[j]) h |= 4;
			if (x[i] > x[j] && y[i] == y[j]) h |= 8;
		}
		ans += h == 15;
	}
	cout << ans << endl;
	{ int _; cin >> _; }
}
