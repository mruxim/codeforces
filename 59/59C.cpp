#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int k, n, m;
string s, t;
bool v[30], imp;

int main()
{
	cin >> k;
	cin >> s;
	n = s.length();
	m = (n + 1) / 2;
	t = s.substr (n / 2);
	reverse (t.begin(), t.end());
	for (int i = 0; i < m; i++)
		if (s[i] != '?' && t[i] != '?' && s[i] != t[i])
			imp = true;
		else if (s[i] == '?')
			s[i] = t[i];
		else
			t[i] = s[i];
	if (imp)
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	int q = 0, r = 0;
	for (int i = 0; i < m; i++)
		if (t[i] == '?')
			q++;
		else
			v[t[i] - 'a'] = true;
	for (int i = 0; i < k; i++)
		if (!v[i])
			r++;
	if (r > q)
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	for (int i = m, j = k; i--; )
	{
		if (t[i] != '?') continue;
		if (r)
		{
			while (v[--j]);
			r--;
			t[i] = j + 'a';
		}
		else
			t[i] = 'a';
	}
	s = t;
	reverse (t.begin(), t.end());
	if (n % 2)
		t = t.substr (1);
	cout << s << t << endl;
	{ int _; cin >> _; }
}
