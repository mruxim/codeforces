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

const int maxn = 100000 + 100;
const int maxm = 1000 + 10;

int n, m;
int f[maxm];

void kmp (string &s, string &t, int *d)
{
	f[0] = 0;
	for (int i = 1, k = 0; i < m; i++)
	{
		while (k > 0 && t[k] != t[i]) k = f[k - 1];
		if (t[i] == t[k]) k++;
		f[i] = k;
	}

	for (int i = 0, k = 0; i < n; i++)
	{
		while (k > 0 && t[k] != s[i]) k = f[k - 1];
		if (s[i] == t[k]) k++;
		d[i] = k;
		if (k == m) k = f[k - 1];
	}
}

string s, sr;
string t, tr;
int d1[maxn], d2[maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> s; n = sz(s);
	sr = s;
	reverse (all(sr));

	int ans = 0;

	int q;
	cin >> q;
	rep (i, q)
	{
		cin >> t; m = sz(t);
		if (m == 1) continue;
		tr = t;
		reverse (all(tr));

		kmp (s, t, d1);
		kmp (sr, tr, d2);

		fer (i, 1, n) d1[i] = max (d1[i], d1[i-1]);
		fer (i, 1, n) d2[i] = max (d2[i], d2[i-1]);

		bool yes = false;
		fer (i, -1, n)
		{
			int j = n-i-2;
			int x = (i >= 0 ? d1[i] : 0);
			int y = (j >= 0 ? d2[j] : 0);
			if (x && y && x + y >= m)
			{
				yes = true;
				break;
			}
		}

		ans += (int)yes;
	}

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
