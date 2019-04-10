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
#include <list>

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

const int maxn = 30000 + 100;

int n;
int a[maxn];

bool is_prog (list<int> &P)
{
	int diff = 0, prev = -1;
	for (int v: P)
	{
		if (prev != -1)
		{
			if (diff == 0) diff = a[v] - a[prev];
			if (a[v] - a[prev] != diff) return false;
		}
		prev = v;
	}
	return true;
}

bool check (int ind1, int ind2)
{
	int cur = a[ind1], diff = a[ind2] - a[ind1];
	list<int> P, Q;
	rep (i, n)
		if (a[i] == cur) P.push_back (i), cur += diff;
		else Q.push_back (i);
	if (Q.empty()) Q.push_back (P.back()), P.pop_back();

	if (!is_prog (Q))
	{
		Q.push_back (P.back());
		inplace_merge (Q.begin(), prev (Q.end()), Q.end());
		P.pop_back();
	}

	if (P.empty()) return false;

	auto it = Q.end(); it--;
	int diff2 = 0;

	while (it != Q.begin())
	{
		auto prv = it; prv--;
		if (diff2 == 0) diff2 = a[*it] - a[*prv];
		if (a[*it] - a[*prv] != diff2)
		{
			if (*prv < P.back() && P.back() < *it && a[*it] - a[P.back()] == diff2)
				Q.insert (it, P.back()), P.pop_back();
			else
				return false;
		}
		it--;
		if (P.empty()) return false;
	}
	for (int v: P) cout << a[v] << ' '; cout << endl;
	for (int v: Q) cout << a[v] << ' '; cout << endl;
	return true;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i];

	if (!check (0, 1)) if (!check (0, 2)) if (!check (1, 2))
		cout << "No solution" << endl;

	{ int _; cin >> _; return 0; }
}
