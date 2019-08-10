ro = int(input())
l = ro * ro
r = (ro + 1) * (ro + 1)
for i in range(10000):
    n = (l + 100 ** i - 1) // (100 ** i)
    m = (l + 100 ** (i + 1) - 1) // (100 ** (i + 1))
    if m * (100 ** (i + 1)) >= r:
        print(n)
        break
