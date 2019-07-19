n, d = map(int, input().split())
x, y = map(int, input().split())

fact = [1]

for i in range(n):
    fact.append(fact[i] * (i + 1))

if x % d != 0 or y % d != 0:
    print(0)
else:
    x = abs(x) // d
    y = abs(y) // d
    sum = 0
    for l in range(n + 1):
        r = x + l
        if (n + y - r - l) % 2 != 0:
            continue
        u = (n + y - r - l) // 2
        d = u - y
        if d < 0 or u < 0:
            continue
        sum += fact[n] // fact[l] // fact[r] // fact[u] // fact[d]
    ans = sum / (4 ** n)
    print("{:.12f}".format(ans))
