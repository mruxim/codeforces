#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
int x, l, r;
string s, t;

int main()
{
	cin >> n >> m;
	l = 1, r = n;
	while (m--)
	{
		cin >> t >> t >> s >> t >> x;
		if (s == "left")
			r = min (r, x - 1);
		else
			l = max (l, x + 1);
	}
	if (l <= r)
		cout << r - l + 1 << endl;
	else
		cout << -1 << endl;
	{ int _; cin >> _; }
}
