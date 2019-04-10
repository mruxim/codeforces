#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXn = 1000 * 1000 + 100;

int n;
int a[MAXn];
int sorted[MAXn];
int L[MAXn], R[MAXn];
int fen[MAXn];
long long res;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	copy (a, a + n, sorted);
	sort (sorted, sorted + n);
	for (int i = 0; i < n; i++)
		a[i] = lower_bound (sorted, sorted + n, a[i]) - sorted + 1;
	for (int i = n; i-- > 0; )
	{
		int x = a[i];
		int sum = 0;
		while (x)
			sum += fen[x], x -= x & -x;
		R[i] = sum;
		x = a[i];
		while (x <= n)
			fen[x]++, x += x & -x;
			
	}
	fill (fen, fen + n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		int x = n - a[i] + 1;
		int sum = 0;
		while (x)
			sum += fen[x], x -= x & -x;
		L[i] = sum;
		x = n - a[i] + 1;
		while (x <= n)
			fen[x]++, x += x & -x;
			
	}
	for (int i = 0; i < n; i++)
		res += (long long)L[i] * (long long)R[i];
	cout << res << endl;
	{ int _; cin >> _; }
}
