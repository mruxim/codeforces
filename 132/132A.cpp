#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;

int main()
{
	getline (cin, s);
	int n = s.length();
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		int x = (int)s[i], pp = x;
		int y = 0;
		for (int j = 0; j < 8; j++)
			y <<= 1, y += x & 1, x >>= 1;
		for (int j = 0; j < 8; j++)
			x <<= 1, x += p & 1, p >>= 1;
		y = (x - y + 256) & 255;
		p = pp;
		cout << y << endl;
	}
	{ int _; cin >> _; }
}
