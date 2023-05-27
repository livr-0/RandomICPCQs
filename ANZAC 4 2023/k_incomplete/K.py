# Fails with WRONG-ANSWER

n, q = (int(n) for n in input().split())
string = list(range(n))
indices = [{i} for i in range(n)]

for _ in range(q):
    query, *args = (int(n) - 1 for n in input().split())
    if query == 0:
        l, r = args
        for i in range(0, (r - l + 1) // 2):
            l_char = string[l + i]
            r_char = string[r - i]
            if l_char == r_char: continue

            r_indices = indices[r - i]
            indices[l + i].update(r_indices)
            for idx in r_indices:
                string[idx] = l_char
        print(string)
    else:
        a, b, x, y = args
        range1 = range(a, b + 1)
        range2 = range(x, y + 1)
        if len(range1) != len(range2):
            print('Not equal')
            continue

        equal = True
        for a, b in zip(range1, range2):
            if string[a] != string[b]:
                equal = False
                break

        if equal:
            print('Equal')
        else:
            print('Unknown')
