// .... .... .....!
// P..... C.....!

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <bitset>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define mkp make_pair
#define all(X) (X).begin(),(X).end()

#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 5000 + 100;

int n;
int a[maxn];
int l[maxn][maxn], r[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i];

	int inv = 0;

	rep (i, n) rep (j, i) if (a[j] > a[i]) inv++;

	fer (i, 1, n)
	{
		copy (l[i-1], l[i-1]+i-1, l[i]);
		l[i][i-1] = a[i-1];
		inplace_merge (l[i], l[i]+i-1, l[i]+i);
	}
	rof (i, n-1, 0)
	{
		copy (r[i+1]+i+2, r[i+1]+n, r[i]+i+2);
		r[i][i+1] = a[i+1];
		inplace_merge (r[i]+i+1, r[i]+i+2, r[i]+n);
	}

	int min_inv = 1e9, cnt = 0;

	rep (i, n) rep (j, i)
	{
		int jl = j - (lower_bound (l[j], l[j]+j, a[j]) - l[j]);
		int jr = (lower_bound (r[j]+j+1, r[j]+n, a[j]) - (r[j]+j+1));
		int il = i - (lower_bound (l[i], l[i]+i, a[i]) - l[i]);
		int ir = (lower_bound (r[i]+i+1, r[i]+n, a[i]) - (r[i]+i+1));

		int cur = inv - jl - jr - il - ir;
		if (a[j] > a[i]) cur++;

		jl = j - (upper_bound (l[j], l[j]+j, a[i]) - l[j]);
		jr = (lower_bound (r[j]+j+1, r[j]+n, a[i]) - (r[j]+j+1));
		il = i - (upper_bound (l[i], l[i]+i, a[j]) - l[i]);
		ir = (lower_bound (r[i]+i+1, r[i]+n, a[j]) - (r[i]+i+1));

		cur += jl + jr + il + ir;
		if (a[i] > a[j]) cur++;

		if (cur < min_inv) min_inv = cur, cnt = 1;
		else if (cur == min_inv) min_inv = cur, cnt++;
	}

	cout << min_inv << ' ' << cnt << endl;

	{ int _; cin >> _; return 0; }
}
