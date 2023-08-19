import itertools

cards = [input() for _ in range(12)]

def is_set(cards):
    colours = [card[0] for card in cards]
    shapes  = [card[1] for card in cards]
    numbers = [card[2] for card in cards]
    fills   = [card[3] for card in cards]

    counts = [
        len(set(colours)),
        len(set(shapes)),
        len(set(numbers)),
        len(set(fills)),
    ]

    return all(count != 2 for count in counts)

for s in itertools.combinations(enumerate(cards), 3):
    if is_set([c[1] for c in s]):
        print(" ".join(str(c[0] + 1) for c in s))
