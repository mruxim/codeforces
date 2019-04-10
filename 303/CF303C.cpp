// .... .... .... !

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

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(),(X).end()

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 5000 + 100;
const int maxd = 1000000 + 100;

int n, k;
int a[maxn];
int v[maxd];

int mark[maxn];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> k;
	rep (i, n) cin >> a[i];
	sort (a, a+n);
	rep (i, n) rep (j, i) v[a[i]-a[j]]++;

	for (int mod = 1; ; mod++)
	{
		int tot = 0;
		for (int p = mod; p <= a[n-1]; p += mod) if ((tot += v[p]) > k*(k+1)/2) break;
		if (tot > k*(k+1)/2) continue;

		int bad = 0;

		for (int i = 0; i < n && bad <= k; i++) bad += (mark[a[i]%mod] == mod), mark[a[i]%mod] = mod;
		if (bad <= k) { cout << mod << endl; break; }
	}

	{ int _; cin >> _; return 0; }
}
