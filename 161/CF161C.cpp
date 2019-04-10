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

bool isin (ll l, ll m, ll r) { return l <= m && m <= r; }

ll f (ll l1, ll r1, ll l2, ll r2, ll step)
{
	if (l1 > r1 || l2 > r2)
		return 0;

	ll ret = 0, mid = 1LL << step;

	r1 -= l1, l1 = (l1-1) % mid + 1, r1 += l1;
	r2 -= l2, l2 = (l2-1) % mid + 1, r2 += l2;

	if ((l1 <= l2 && r2 <= r1) || (l2 <= l1 && r1 <= r2))
		return min (r1, r2) - max (l1, l2) + 1;

	if (isin (l1, mid, r1) && isin (l2, mid, r2))
		ret = min (mid - l1, mid - l2) + min (r1 - mid, r2 - mid) + 1;

	cmx (ret, f (l1, min (r1, mid-1), l2, min (r2, mid-1), step-1));
	cmx (ret, f (max (l1, mid+1), r1, l2, min (r2, mid-1), step-1));
	cmx (ret, f (max (l1, mid+1), r1, max (l2, mid+1), r2, step-1));
	cmx (ret, f (l1, min (r1, mid-1), max (l2, mid+1), r2, step-1));

	return ret;
}

int main()
{
	ll l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	cout << f (l1, r1, l2, r2, 35) << endl;
	{ ll _; cin >> _; }
}

//abacabadabacaba
//1234567890
