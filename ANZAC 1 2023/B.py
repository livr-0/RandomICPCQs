line = input()
d, f = line.split()
for i, c in enumerate(f):
    if c < d:
        print(d + c, end="")
        break
    else:
        print(c, end="")
else:
    print(d, end="")
print(f[i+1:], end="")
print()
