n,m = map(int, input().split())
a = []
for i in range(m):
    a.append(tuple(int(x) - 1 for x in input().split()))
p = [0]*n
cur = 0
for i in range(m):
    if a[i][0] != a[0][0] and a[i][1] != a[0][0]:
        p[a[i][0]] += 1
        p[a[i][1]] += 1
    else:
        cur += 1
for i in range(n):
    if cur + p[i] == m:
        print("YES")
        exit(0)
cur = 0
p = [0]*n
for i in range(m):
    if a[i][0] != a[0][1] and a[i][1] != a[0][1]:
        p[a[i][0]] += 1
        p[a[i][1]] += 1
    else:
        cur += 1
for i in range(n):
    if cur + p[i] == m:
        print("YES")
        exit(0)
print("NO")