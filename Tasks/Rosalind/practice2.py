from random import random
 
m1 = int(input())
m2 = int(input())
n = int(random() * (m2-m1+1)) + m1
print(n)
 
m1 = float(input())
m2 = float(input())
n = random() * (m2-m1) + m1
print(round(n,3))
 
m1 = ord(input())
m2 = ord(input())
n = int(random() * (m2-m1+1)) + m1
print(chr(n))
