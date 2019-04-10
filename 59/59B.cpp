#include <iostream>

using namespace std;

int n;
int a, s, mo = 1 << 20;

int main()
{
	cin >> n;
	while (n--)
	{
		cin >> a;
		s += a;
		if (a & 1)
			mo = min (mo, a);
	}
	cout << ((s & 1) ? s : max (s - mo, 0)) << endl;
	{ int _; cin >> _; }
}
