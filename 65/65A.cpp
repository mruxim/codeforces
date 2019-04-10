#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;
int n;

int main()
{
	cin >> s;
	n = s.length();
	if (s[0] == '-')
	{
		s = s.substr (1);
		int k;
		for (k = n-1; s[--k] == '0'; );
		s[k] = s[k]-1;
		if (s[0] == '0')
			s = s.substr (1);
		n = s.length();
	}
	if (n < 3 || (n == 3 && s <= "127"))
		cout << "byte" << endl;
	else if (n < 5 || (n == 5 && s <= "32767"))
		cout << "short" << endl;
	else if (n < 10 || (n == 10 && s <= "2147483647"))
		cout << "int" << endl;
	else if (n < 19 || (n == 19 && "9223372036854775807"))
		cout << "long" << endl;
	else
		cout << "BigInteger" << endl;
	{ int _; cin >> _; }
}
