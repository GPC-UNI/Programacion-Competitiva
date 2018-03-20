l, r, k = map(int, input().split())
ans = []
p = 1
while True:
    if l <= p <= r: ans += [p]
    if p > r: break
    p *= k
print(-1 if len(ans) == 0 else ' '.join(str(ans_i) for ans_i in ans));
