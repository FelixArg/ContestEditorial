n = int(input())
a = [int(x) - 1 for x in input().split()]
pos = [0]*n
for i in range(n):
    pos[a[i]] = i
ans = [1]*n
for i in range(n):
    if a[i] > 0 and pos[a[i] - 1] < i:
        ans[a[i]] = ans[a[i] - 1] + 1
print(n - max(ans))