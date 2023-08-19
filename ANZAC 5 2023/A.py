girls = input().split()
n = int(input())

for _ in range(n):
    x, y = (int(v) for v in input().split())
    x -= 1
    y -= 1
    girls[x], girls[y] = girls[y], girls[x]

print(" ".join(girls))
