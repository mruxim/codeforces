n, d = int(input()), {'#' : 0}
for i in range(4):
	for x in input().replace('.',''):
		d[x] = d.setdefault (x, 0) + 1
print ("YES" if max (d.values()) <= 2*n else "NO")

