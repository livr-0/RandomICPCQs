from random import choices, shuffle
from string import ascii_uppercase

n = 1000
k = 3

dna = "".join(choices(ascii_uppercase, k=n))
print(f"Original: {dna}")

substrings = []
for i in range(n - k + 1):
    substrings.append(dna[i:i+k])

papers = []
for a, b in zip(substrings, substrings[1:]):
    papers.append((a, b))

shuffle(papers)

with open("G.in", "w") as f:
    f.write(f"{n} {k}\n")
    for paper in papers:
        f.write(f"{paper[0]} {paper[1]}\n")
