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
#include <unordered_map>

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

const int maxs = 30;

int mul[maxs];
unordered_map<int, int> cache;

int calc (int mask)
{
	int &ret = cache[mask];
	if (ret) return ret;

	int ex = (1<<maxs)-1;
	rep (i, maxs) if (mask >> i & 1) ex &= ~calc (mask & mul[i]);

	return ret = ex&-ex;
}

int n;
int nim[maxs];
//int nim[maxs] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
set<int> mark;

int main()
{
	ios_base::sync_with_stdio (false);

	rep (i, maxs) rep (j, maxs) if ((j+1) % (i+1)) mul[i] |= 1 << j;
	cache.max_load_factor (0.30); cache.reserve (750000);
	rep (i, maxs) nim[i] = __builtin_ctz (calc ((1<<i)-1));
//	rep (i, maxs) cerr << (i ? ", " : " = {") << nim[i]; cerr << "};" << endl;

	cin >> n;
	int rem = n;
	int ans = 0;
	for (int i = 2; i*i <= n; i++)
	{
		if (mark.find (i) != mark.end()) continue;
		int len = 0;
		for (ll cur = i; cur <= n; cur *= i)
		{
			mark.insert (cur);
			len++; rem--;
		}
		ans ^= nim[len];
	}
	ans ^= rem % 2;
	cout << (ans ? "Vasya" : "Petya") << endl;

	{ return 0; }
}

