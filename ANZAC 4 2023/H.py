length = int(input())

samples = [int(n) for n in input().split()]

extremes = [samples[0], samples[1]]
for sample in samples[2:]:
    if extremes[-2] > extremes[-1] > sample or extremes[-2] < extremes[-1] < sample:
        extremes[-1] = sample
    elif sample != extremes[-1]:
        extremes.append(sample)

best = 0
for i in range(len(extremes) - 2):
    if extremes[i] < extremes[i + 1] > extremes[i + 2]:
        best = max(best, min(extremes[i + 1] - extremes[i], extremes[i + 1] - extremes[i + 2]))

print(best)
