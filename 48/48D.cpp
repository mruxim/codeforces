#include <iostream>

using namespace std;

int n;
int a[200000];
int l[200000];
int t[200000];
bool y;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], a[i]--;
	y = true;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= n)
		{
			y = false;
			break;
		}
		t[a[i]]++;
	}
	for (int i = 1; i < n; i++)
		if (t[i] > t[i-1])
			y = false;
	if (y == false)
		cout << -1 << endl;
	else
	{
		cout << t[0] << endl;
		for (int i = 0; i < n; i++)
			cout << ++l[a[i]] << ' ';
		cout << endl;
	}
	{ int _; cin >> _; }
}
