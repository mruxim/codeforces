#include<cstdio>

long long n, m, c;
char s[112345];

int main() {
	scanf("%lld%lld %s", &n, &m, s); m--;

	int p = 0;
	for(int i = 1; i < n; i++) {
		if(s[i] == s[i-1]) c += n * m, p = i;
		else if(s[i] != s[i-2]) p = i - 1;
		c += i - p;
	}

	printf("%I64d\n", n * n * m - c);

	return 0;
}
