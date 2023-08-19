n = int(input())
votes = [input() for _ in range(n)]
freqs = {}
for vote in votes:
    freqs[vote] = freqs.get(vote, 0) + 1

l = list(sorted(freqs.items(), key=lambda x: x[1]))
m = l[-1][1]

winners = []
m2 = 0
for name, score in l:
    if score == m:
        winners.append(name)
    elif score > m2:
        m2 = score

if len(winners) == 1:
    lead = m-m2
    print(f"{winners[0]} won by {lead} vote{'' if lead == 1 else 's'}.")
else:
    winner_text = ", ".join(sorted(winners))
    print(f"Tie between {winner_text}.")
