import math

n = int(input())
for i in range(n):
    cumprimentos = int(input())
    delta = 1 -(4*1*(-2*cumprimentos))
    x1 = (1 + math.sqrt(delta)) / 2
    print(int(x1))