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

struct cmp {
	bool operator ()(const pii &p, const pii &q) const {
		return p.X+p.Y != q.X+q.Y ? p.X+p.Y < q.X+q.Y : p.X < q.X;
	}
};

int n;
int a[(int)5e5+5];
int C, V;
multiset <pii, cmp> S, T;
ll cost;

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i];
	sort (a, a+n);

	for (int i = n; i--; )
	{
		int j = i;
		while (j && a[j-1] == a[i]) j--;

		int cnt = i-j+1, val = a[i];
		while (cnt)
		{
			if (C && val < V)
			{
				T.insert (pii (val, V));
				C--;
				cnt--;
			}
			else if (cnt >= 2 && !S.empty() && S.begin()->X < 2*val)
			{
				pii tmp = *S.begin();
				S.erase (S.begin());
				T.insert (pii (val, tmp.X));
				T.insert (pii (val, tmp.Y));
				cost += tmp.X;
				cnt -= 2;
			}
			else
				C++, V = val, cnt--, cost += val;
		}

		for (auto p: T) S.insert (p);
		T.clear();

		i = j;

		cerr << " ! " << C << ' ' << V << endl;
		for (auto p: S) cerr << " @ " << p.X << ' ' << p.Y << endl;
		cerr << endl;
	}


	cout << cost << endl;

	{ int _; cin >> _; return 0; }
}
