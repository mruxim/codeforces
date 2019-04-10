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

const int maxn = 200000;
const int maxm = 100000 + 100;

int m;
int t[maxm], x[maxm], l[maxm], c[maxm];
ll r[maxm];

int n = 0;
int a[maxn+100];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> m;
	ll cur = 0;
	rep (i, m)
	{
		cin >> t[i];
		if (t[i] == 1)
		{
			cin >> x[i];
			if (n < maxn) a[n++] = x[i];
			r[i] = cur = cur+1;
		}
		else
		{
			cin >> l[i] >> c[i];
			rep (j, c[i])
			{
				if (n >= maxn) break;
				rep (k, l[i]) { a[n++] = a[k]; if (n >= maxn) break; }
			}
			r[i] = cur = cur + l[i]*(ll)c[i];
		}
	}

	int id = 0;

	int q;
	cin >> q;
	while (q--)
	{
		ll pos;
		cin >> pos, pos--;
		while (r[id] <= pos) id++;
		if (t[id] == 1) cout << x[id] << ' ';
		else
		{
			ll st = r[id] - l[id]*(ll)c[id];
			int p = (pos - st) % l[id];
			cout << a[p] << ' ';
		}
	}
	cout << endl;

	{ return 0; }
}

