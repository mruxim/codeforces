#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string s;
int x;

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		if (islower (s[i]))
			x++;
	for (int i = 0; i < s.length(); i++)
		s[i] = (x < s.length() - x) ? toupper (s[i]) : tolower (s[i]);
	cout << s << endl;
	{ int _; cin >> _; }
}
