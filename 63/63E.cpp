#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int n = 19;

char dp[1 << n];
int moves[1000], mlen;

void add_moves (int *arr, int *tlen)
{
	for (int z = 0; z < 5; z++)
		for (int i = tlen[z]; i < tlen[z+1]; i++)
			for (int j = i; j < tlen[z+1]; j++)
			{
				int x = 0;
				for (int k = i; k <= j; k++)
					x |= 1 << arr[k];
				moves[mlen++] = x;
			}
}

void make_moves ()
{
	int a[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
	int b[n] = {7, 3, 0, 12, 8, 4, 1, 16, 13, 9, 5, 2, 17, 14, 10, 6, 18, 15, 11};
	int c[n] = {2, 6, 11, 1, 5, 10, 15, 0, 4, 9, 14, 18, 3, 8, 13, 17, 7, 12, 16};
	int tlen[6] = {0, 3, 7, 12, 16, 19};
	add_moves (a, tlen);
	add_moves (b, tlen);
	add_moves (c, tlen);
	sort (moves, moves + mlen);
	mlen = unique (moves, moves + mlen) - moves;
}

bool solve (int state)
{
	if (state == (1 << n) - 1) return false;
	if (dp[state]) return (dp[state] == 2 ? false : true);
	dp[state] = 2;
	for (int i = 0; i < mlen; i++)
		if ((state & moves[i]) == 0)
			if (solve (state | moves[i]) == false)
			{
				dp[state] = 1;
				break;
			}
	return (dp[state] == 2 ? false : true);
}

int main()
{
	int state = 0;
	for (int i = 0; i < n; i++)
	{
		char tmp;
		cin >> tmp;
		if (tmp == 'O')
			state |= 1 << i;
	}

	make_moves ();
//	cerr << mlen << endl;

	solve (state);

	if (dp[state] == 1)
		cout << "Karlsson" << endl;
	else
		cout << "Lillebror" << endl;
	{ int _; cin >> _; }
}
