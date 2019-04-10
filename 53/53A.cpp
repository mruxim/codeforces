#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string s, t[1000];

int main()
{
	cin >> s;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[i];
	sort (t, t + n);
	bool b = false;
	for (int i = 0; i < n; i++)
		if (t[i].substr (0, s.length()) == s)
		{
			cout << t[i] << endl;
			b = true;
			break;
		}
	if (!b)
		cout << s << endl;
	{ int _; cin >> _; }
}
