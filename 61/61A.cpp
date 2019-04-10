#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < (int)s.length(); i++)
		cout << ((s[i] - '0') ^ (t[i] - '0'));
	cout << endl;
	{ int _; cin >> _; }
}
