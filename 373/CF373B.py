w, m, k = map(int, input().split())
w = w // k
r = 0
for i in range(1, 20):
	a = min (w // i, max(0, 10 ** i - m))
	r += a
	w -= a*i
	m = max (m, 10**i)
print (r)

