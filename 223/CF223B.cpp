// .... .... .... !

#include <iostream>
#include <fstream>

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

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 200 * 1000 + 1000;

string s, t;
int n, m;
int a[maxn], b[maxn];

int main()
{
	cin >> s >> t;
	n = s.length(), m = t.length();
	int p = 0;
	rep (i, m)
	{
		while (p < n && s[p] != t[i]) p++;
		if (p >= n)
		{
			cout << "No" << endl;
			return 0;
		}
		a[i] = p;
		p++;
	}
	p = n-1;
	rof (i, m, 0)
	{
		while (p >= 0 && s[p] != t[i]) p--;
		b[i] = p;
		p--;
	}

	fer (ch, 'a', 'z'+1)
	{
		int pos = 0;
		rep (i, n) if (s[i] == ch)
		{
			while (1)
			{
				while (pos < m && t[pos] != ch) pos++;
				if (pos >= m) { cout << "No" << endl; return 0; }
				if (a[pos] <= i && b[pos] >= i) break;
				pos++;
			}
		}
	}

	cout << "Yes" << endl;

	{ int _; cin >> _; }
	return 0;
}
