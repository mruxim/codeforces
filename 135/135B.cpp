#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long x[10], y[10];
long long d[50];

int main()
{
	for (int i = 0; i < 8; i++)
		cin >> x[i] >> y[i];
	string s ("00001111");
	do {
		int p;
		bool ok = true;
		p = 0;
		for (int i = 0; i < 8; i++) if (s[i] == '0') for (int j = i+1; j < 8; j++) if (s[j] == '0')
			d[p++] = (x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]);
		sort (d, d + 6);
		if (d[0]==0 || d[0]!=d[1] || d[2]!=d[3] || d[4]!=d[5] || d[0]+d[2]!=d[4])
			ok = false;

		p = 0;
		for (int i = 0; i < 8; i++) if (s[i] == '1') for (int j = i+1; j < 8; j++) if (s[j] == '1')
			d[p++] = (x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]);
		sort (d, d + 6);
		if (d[0]==0 || d[0]!=d[1] || d[2]!=d[3] || d[4]!=d[5] || d[0]+d[2]!=d[4] || d[0]!=d[2])
			ok = false;

		if (ok)
		{
			cout << "YES" << endl;
			for (int i = 0; i < 8; i++)
				if (s[i] == '1')
					cout << i+1 << ' ';
			cout << endl;
			for (int i = 0; i < 8; i++)
				if (s[i] == '0')
					cout << i+1 << ' ';
			cout << endl;
		{ int _; cin >> _; }
			return 0;
		}
	} while (next_permutation (s.begin(), s.end()));
	cout << "NO" << endl;
	{ int _; cin >> _; }
}
