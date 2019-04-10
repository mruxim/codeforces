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

ll n;
vector<ll> d;
int ans;

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;

	if (n % 3) { cout << 0 << endl; goto halt; }
	n /= 3;

	for (ll i = 2; i*i <= n; i++) if (n % i == 0) d.pb (i);

	for (int i = 0; i < sz(d) && d[i]*d[i]*d[i] <= n; i++)
	{
		ll n1 = n / d[i];
		for (int j = i; j < sz(d) && d[j]*d[j] <= n1; j++) if (n1 % d[j] == 0)
		{
			ll ab = d[i], ac = d[j], bc = n1 / d[j];
			if ((ab + ac + bc) % 2 || ab + ac - bc <= 0) continue;
			if (ab == ac && ac == bc) ans += 1;
			else if (ab == ac || ac == bc || bc == ab) ans += 3;
			else ans += 6;
		}
	}
	cout << ans << endl;

	halt: { int _; cin >> _; return 0; }
}
