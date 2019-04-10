#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define abs(x) ((x)<0?-(x):(x))

int main()
{
	int a, b, c, d;
	cin >> a >> b;
	cin >> c >> d;
	if ((d >= a-1 && d <= 2*a+2) ||
		(c >= b-1 && c <= 2*b+2))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	{ int _; cin >> _; }
}
