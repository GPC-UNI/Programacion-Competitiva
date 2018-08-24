# Pregunta con truco, recuerden usar Python de vez en cuando.

t = int(input())
while t > 0:
    a,b = [int(x) for x in input().split()]
    print(a*b)
    t = t - 1
