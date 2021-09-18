n,k,a,b = map(int, input().split())
s = []
lastGcnt = 0
lastBcnt = 0
for i in range(n):
    if a > b:
        if lastGcnt + 1 > k:
            if b == 0:
                print("NO")
                exit(0)
            else:
                lastGcnt = 0
                lastBcnt = 1
                b -= 1
                s.append('B')
        else:
            lastBcnt = 0
            lastGcnt += 1
            a -= 1
            s.append('G')
    else:
        if lastBcnt + 1 > k:
            if a == 0:
                print("NO")
                exit(0)
            else:
                lastBcnt = 0
                lastGcnt = 1
                a -= 1
                s.append('G')
        else:
            lastGcnt = 0
            lastBcnt += 1
            b -= 1
            s.append('B')
print(''.join(s))

