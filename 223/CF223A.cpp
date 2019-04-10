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

const int maxn = 1000000 + 100;

int n;
string s;
int a[maxn], c[maxn], t = 0;
int beg[maxn];
int l, r;

int main()
{
	cin >> s;
	n = s.length();
	rep (i, n)
		c[1+i] = c[i] + (s[i] == '[');

	l = 0, r = 0;
	memset (beg, -1, sizeof beg);

	rep (i, n)
	{
		if (s[i] == '(' || s[i] == '[') { a[t++] = i; continue; }
		else if (t == 0 || (s[i] == ')' && s[a[t-1]] == '[')) t = 0;
		else if (t == 0 || (s[i] == ']' && s[a[t-1]] == '(')) t = 0;
		else
		{
			beg[i] = a[t-1];
			int x = a[t-1], y = i+1;
			if (x && beg[x-1] != -1) x = beg[i] = beg[x-1];
			if (c[y] - c[x] >= c[r] - c[l])
				l = x, r = y;
			t--;
		}
	}

	if (l == 0 && r == 0)
		cout << 0 << endl;
	else
	{
		cout << c[r] - c[l] << endl;
		cout << s.substr (l, r - l) << endl;
	}

	{ int _; cin >> _; }
	return 0;
}
