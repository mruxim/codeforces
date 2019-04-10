// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

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

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 3*100000 + 1000;
const int K = 50;

int n;
pii arr[maxn];
set<int> s;
vector<int> L[maxn], R[maxn]; 

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> arr[i].X, arr[i].Y = i;

	sort (arr, arr+n, greater<pii>());

	rep (p, n)
	{
		auto cur = s.insert (arr[p].Y).first, it = cur;
		auto &CL = L[arr[p].Y], &CR = R[arr[p].Y];

		rep (i, K)
		{
			it++; if (it == s.end()) break;
			CR.pb (*it);
		}
		it = cur;
		rep (i, K)
		{
			if (it == s.begin()) break; it--;
			CL.pb (*it);
		}

		while (sz(CL) <= K) CL.pb(-1);
		while (sz(CR) <= K) CR.pb(n);
	}

	vector<double> pow2;
	pow2.pb (1.0);
	rep (i, K) pow2.pb (pow2.back() * 2.0);

	double res = 0;
	rep (i, n)
	{
		double cur = 0;
		rep (x, K)
		{
			int rgt = R[arr[i].Y][x] - (x ? R[arr[i].Y][x-1] : arr[i].Y);
			cur += arr[i].X * (ll)rgt / pow2[x];
		}

		rep (x, K)
		{
			int lft = L[arr[i].Y][x] - (x ? L[arr[i].Y][x-1] : arr[i].Y);
			res += cur * lft / pow2[x+1];
		}
	}

	cout << fixed << setprecision (10) << -res/n/n << endl;
	{ return 0; }
}

