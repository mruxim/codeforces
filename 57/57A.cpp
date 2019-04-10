#include <iostream>
#include <cmath>

using namespace std;

int n, X1, Y1, X2, Y2;

int main()
{
	cin >> n >> X1 >> Y1 >> X2 >> Y2;
	if (X1 != 0 && X1 != n)
		swap (X1, Y1), swap (X2, Y2);
	if (X1 == n)
		X1 = n - X1, X2 = n - X2;
	int ans;
	if (X2 == 0)
		ans = Y1 > Y2 ? Y1 - Y2 : Y2 - Y1;
	else if (X2 == n)
		ans = n + min (Y1 + Y2, n - Y1 + n - Y2);
	else if (Y2 == 0)
		ans = Y1 + X2;
	else
		ans = n - Y1 + X2;
	cout << ans << endl;
	{ int _; cin >> _; }
}
