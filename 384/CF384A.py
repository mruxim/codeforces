n = int(input())
print((n*n+1)//2)
for i in range(n):	
	print(('C.'*600)[i%2:i%2+n])
