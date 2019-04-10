n = int(input())
a = []
for i in range(n):
	a.extend(zip(map(int, input().split()), [0, 1]))
c = [0]*2
for v, i in sorted(a)[:n]: c[i] += 1
for i in range(2):
	c[i] = max(c[i], n//2)
	print('1' * c[i] + '0' * (n-c[i]))
