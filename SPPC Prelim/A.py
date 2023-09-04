import itertools

count = int(input())

cards = []
for _ in range(count):
    cards.append(input().split())

for maybe_set in itertools.combinations(enumerate(cards), 3):
    for i in range(4):
        props = [card[1][i] for card in maybe_set]
        if len(set(props)) == 2:
            break
    else:
        print(" ".join(str(card[0] + 1) for card in maybe_set))
        break
else:
    print(0)
