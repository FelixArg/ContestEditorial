n = int(input())
max_value = -10**18
min_value = 10**18
for i in range(n):
    x = int(input())
    max_value = max(max_value, x)
    min_value = min(min_value, x)
if min_value >= -128 and max_value <= 127:
    print("byte")
elif min_value >= -32768 and max_value <= 32767:
    print("short")
elif min_value >= -2147483648 and max_value <= 2147483647:
    print("int")
else:
    print("long")