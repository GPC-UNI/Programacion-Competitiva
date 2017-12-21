'''
By: Victoralin10
'''
 
n = int(input())
print ("SI" if n == sum([x for x in range(1, n) if n%x == 0]) else "No")

