# Generate a large random input for problem K

from random import randint, random

print('10000 20000')
for _ in range(20000):
    if random() < 0.5:
        l = randint(1, 10000)
        r = randint(l, 10000)
        print(f'1 {l} {r}')
    elif random() < 0.99:
        a = randint(1, 10000)
        b = randint(a, 10000)
        x = randint(1, 10000 - b + a)
        y = x + b - a
        print(f'2 {a} {b} {x} {y}')
    else:
        a = randint(1, 10000)
        b = randint(a, 10000)
        x = randint(1, 10000)
        y = randint(x, 10000)
        print(f'2 {a} {b} {x} {y}')
