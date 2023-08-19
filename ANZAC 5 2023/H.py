green_len, red_len = [int(x) for x in input().split()]
number, time = [int(x) for x in input().split()]
cars = [time] * number
count = int(input())

max_count = number
max_time = time

for _ in range(count):
    t, c = input().split()
    c = int(c)
    if t == "R":
        cars += [0] * c
        cars = [car + red_len for car in cars]
    elif t == "G":
        cars = cars[c:]
        cars = [car + green_len for car in cars]
    max_count = max(len(cars), max_count)
    if len(cars) > 0:
        max_time = max(max(cars), max_time)

def pl(n, t):
    if n != 1:
        t += "s"
    return f"{n} {t}"

print(f"Longest queue was {pl(max_count, 'vehicle')}.")
print(f"Longest through time was {pl(max_time // 60, 'minute')} and {pl(max_time % 60, 'second')}.")
