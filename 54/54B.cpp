#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int a, b;
char s[50][50];
int ans, rx, ry;

int main()
{
	cin >> a >> b;
	rx = a, ry = b;
	for (int i = 0; i < a; i++)
		cin >> s[i];
	for (int i = 1; i <= a; i++)  for (int j = 1; j <= b; j++) if (a % i == 0 && b % j == 0)
	{
		int x = a / i, y = b / j;
//			cerr << x << ' ' << y << endl;
		bool ok = true;
		for (int p = 0; p < i && ok; p++) for (int q = 0; q < j && ok; q++)
		for (int pp = 0; ok && pp <= p; pp++) for (int qq = 0; ok && qq < (pp==p ? q : j); qq++)
		{
			int o1 = 0, o2 = 0, o3 = 0, o4 = 0;
			for (int g = 0; g < x && !o1; g++) for (int h = 0; h < y && !o1; h++)
			if (s[p*x+g][q*y+h] != s[pp*x+g][qq*y+h]) o1 = 1;

			for (int g = 0; g < x && !o2; g++) for (int h = 0; h < y && !o2; h++)
			if (s[p*x+x-g-1][q*y+y-h-1] != s[pp*x+g][qq*y+h]) o2 = 1;

			if (x == y)
			{
				for (int g = 0; g < x && !o3; g++) for (int h = 0; h < y && !o3; h++)
				if (s[p*x+x-h-1][q*y+g] != s[pp*x+g][qq*y+h]) o3 = 1;

				for (int g = 0; g < x && !o4; g++) for (int h = 0; h < y && !o4; h++)
				if (s[p*x+h][q*y+y-g-1] != s[pp*x+g][qq*y+h]) o4 = 1;
			}
			else
				o3 = o4 = 1;
			if (!(o1 && o2 && o3 && o4))
				ok = false;
		}
		if (ok)
		{
//			cerr << x << ' ' << y << endl;
			ans++;
			if (x*y < rx*ry || (x*y == rx*ry && x < rx))
				rx = x, ry = y;
		}
	}
	cout << ans << endl << rx << ' ' << ry << endl;
	{ int _; cin >> _; }
}
