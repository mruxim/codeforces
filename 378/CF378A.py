a, b = map(int, input().split())
if a == b:
	print (0, 6, 0)
elif a < b:
	print ((a+b-1)//2, (a+b+1)%2, 6-(a+b)//2)
else:
	print (6-(a+b)//2, (a+b+1)%2, (a+b-1)//2)

