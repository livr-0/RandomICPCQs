n = int(input())

scores = [0] * 75

for _ in range(n):
    t, x, y = input().split()
    x, y = int(x), int(y)
    if t == "G":
        scores[x * 5 + y] += 1
    elif t == "S":
        scores[x * 5 + y] -= 1

m = max(scores)

best = []
for i, score in enumerate(scores):
    if score == m:
        best.append((i // 5, i % 5))

if len(best) == 1:
    print(f"Best place {best[0][0]} {best[0][1]}.")
else:
    places = ", ".join(f"{s[0]} {s[1]}" for s in best)
    print(f"Best places {places}.")
