// Author: MohammadReza Maleki (MrM)

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i < _n; i++)
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define cmx(a, b) a = max(a,b)
#define cmn(a, b) a = min(a,b)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
typedef vector <int> vi;

////////////////////////////////////////////////

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string s, t;
	if (abs (c - d) > 1) cout << -1 << endl;
	else if (c == d)
	{
		if (a >= c+1 && b >= c)
		{
			s = string (a-c, '4');
//			s += string (c-1, "74");
			t.resize (2*c-2); rep (i, c-1) t[2*i] = '7', t[2*i+1] = '4'; s += t;
			s += string (b-c+1, '7');
			s += '4';
		}
		else if (b >= c+1 && a >= c)
		{
			s = string (b-c, '7');
//			s = string (c-1, "74") + s;
			t.resize (2*c-2); rep (i, c-1) t[2*i] = '7', t[2*i+1] = '4'; s = t + s;
			s = string (a-c+1, '4') + s;
			s = '7' + s;
		}
		else
			s = "-1";
	}
	else if (c == d+1)
	{
		if (a >= c && b >= c)
		{
			s = string (a - c, '4');
//			s += string (c, "47");
			t.resize (2*c); rep (i, c) t[2*i] = '4', t[2*i+1] = '7'; s += t;
			s += string (b - c, '7');
		}
		else
		s = "-1";
	}
	else if (c == d-1)
	{
		if (a >= d && b >= d)
		{
			s = '7' + string (a - d + 1, '4');
//			s += string (d-2, "74");
			t.resize (2*d-4); rep (i, d-2) t[2*i] = '7', t[2*i+1] = '4'; s += t;
			s += string (b - c, '7') + '4';
		}
		else
		s = "-1";
	}
	cout << s << endl;
	{ int _; cin >> _; }
}
