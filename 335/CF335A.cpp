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

string s;
int n;
int cnt[33];

int main()
{
	ios::sync_with_stdio (false);

	cin >> s >> n;
	rep (i, sz(s)) cnt[s[i]-'a']++;
	fer (k, 1, 2000)
	{
		string ans = "";
		fer (i, 0, 26)
		{
			int x = 0;
			while (x*k < cnt[i])
				ans += char(i+'a'), x++;
		}
		if (sz(ans) > n) continue;
		while (sz(ans) < n)
			ans += 'a';
		cout << k << endl;
		cout << ans << endl;
		return 0;
	}
	cout << -1 << endl;

	{ int _; cin >> _; return 0; }
}
