from functools import *; from fractions import*
print(int(input()) * reduce(gcd,map(int,input().split())))

