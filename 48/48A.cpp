#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s[3];
	string a[] = {"rock" ,"paper", "scissors"};
	bool w = false;
	cin >> s[0] >> s[1] >> s[2];
	for (int i = 0; i < 3; i++)
	{
		int j;
		for (j = 0; s[i] != a[j]; j++);
		if (s[(i+1) % 3] == a[(j+2) % 3] && s[(i+2) % 3] == a[(j+2) % 3])
			cout << ("FMS"[i]) << endl, w = true;
	}
	cout << (w ? "" : "?\n") << endl;
	{ int _; cin >> _; }
}
