import sys
import bisect as bs
 
ls = []
ls.append(-4) # in case jl is less than 5
for l in range(1, 12):
  for i in range(1<<l):
    x = ("{0:0" + str(l) + "b}").format(i)
    x = x.replace('0', '4')
    x = x.replace('1', '7')
    ls.append(int(x))
 
def intersect(low, high, rl, rr):
  left = max(low, rl)
  right = min(high, rr)
  return max(right - left + 1, 0)
 
line = sys.stdin.readline()
jl, jr, rl, rr, k = (int(x) for x in line.split(' '))
 
ans = 0
 
# next lucky greater than or equal jl
ind = bs.bisect_left(ls, jl)
 
# sliding window over the intervals of possible values of J covering [jl, jr]
while ls[ind - 1] + 1 <= jr:
  kth_next = ind + k - 1
 
  if kth_next + 1 < len(ls):
    high = ls[kth_next + 1] - 1
  else:
    high = ls[-1] # last element
 
  if kth_next < len(ls):
    low = ls[kth_next]
  else:
    low = ls[-1] # last element
 
  j_low = ls[ind - 1] + 1
  j_high = ls[ind]
 
  # get range of values for J
  v1 = intersect(j_low, j_high, jl, jr)
 
  # get range of values for R
  v2 = intersect(low, high, rl, rr)
 
  ans += v1 * v2
  ind += 1
 
all_cases = (jr - jl + 1) * (rr - rl + 1)
 
print(ans/all_cases)
