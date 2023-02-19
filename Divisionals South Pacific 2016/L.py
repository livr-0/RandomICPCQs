import sys

l, r, n, c = (int(i) for i in input().split())
conflicts = {i: [] for i in range(n)}
for i in range(c):
    a, b = (int(i) for i in input().split())
    conflicts[a].append(b)
    conflicts[b].append(a)

groups = []
while conflicts:
    first = next(iter(conflicts.keys()))
    a, b = {first}, set()
    scanning = {first}
    while scanning:
        chem = scanning.pop()
        for conf in conflicts[chem]:
            if chem in a:
                b.add(conf)
            else:
                a.add(conf)
            if conf in conflicts:
                scanning.add(conf)
        del conflicts[chem]
    if a & b:
        print("No")
        sys.exit()
    groups.append((len(set(a)), len(set(b))))

wave = {0}
for group in groups:
    wave = {c + n for c in wave for n in group if c + n <= l}
    if len(wave) == 0:
        print("No")
        sys.exit()

l_filled = max(wave)
r_filled = n - l_filled

if l_filled <= l and r_filled <= r:
    print("Yes")
else:
    print("No")
