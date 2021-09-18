n,k = map(int,input().split())
ans = 0
while n != 1 and k != 0:
    n += 1
    while n % 3 == 0:
        n //= 3
        ans += 1
    k -= 1
ans += k // 2
print(ans)