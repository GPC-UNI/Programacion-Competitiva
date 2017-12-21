'''
By: Victoralin10
'''
 
notas = [int(x) for x in input().split()]
a = [0 if x == -1 else x for x in notas]
b = [20 if x == -1 else x for x in notas]
 
ans = 0
for pc1 in range(a[0], b[0] + 1):
    for pc2 in range(a[1], b[1] + 1):
        for pc3 in range(a[2], b[2] + 1):
            for pc4 in range(a[3], b[3] + 1):
                for ep in range(a[4], b[4] + 1):
                    for ef in range(a[5], b[5] + 1):
                        ans += (pc1 + pc2 + pc3 + pc4 - min([pc1, pc2, pc3, pc4])  + (ep + ef)*3>= 90)
print(ans)
