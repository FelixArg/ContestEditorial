n = int(input())
s = input()
ans = 21
t = ""
p = []

def brute(pos, bal1, bal2, cur):
    if pos == n:
        global ans
        global t
        if bal1 == 0 and bal2 == 0 and cur < ans:
            ans = cur
            t = ''.join(p)
        return
    if bal1 < 0 or bal2 < 0:
        return
    for x in "()[]":
        p.append(x)
        if x == '(':
            bal1 += 1
        elif x == '[':
            bal2 += 1
        elif x == ')':
            bal1 -= 1
        else:
            bal2 -= 1
        if x != s[pos]:
            cur += 1
        brute(pos + 1, bal1, bal2, cur)
        p.pop()
        if x == '(':
            bal1 -= 1
        elif x == '[':
            bal2 -= 1
        elif x == ')':
            bal1 += 1
        else:
            bal2 += 1
        if x != s[pos]:
            cur -= 1


brute(0, 0, 0, 0)
print(ans)
print(t)
