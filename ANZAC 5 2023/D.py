target = input()

def score(guess):
    target_chars = list(target)
    guess_chars = list(guess)
    bulls, cows = 0, 0
    for i in range(4):
        if target_chars[i] == guess_chars[i]:
            bulls += 1
            target_chars[i] = "$"
            guess_chars[i] = "#"
    for char in guess_chars:
        if char in target_chars:
            cows += 1
            target_chars[target_chars.index(char)] = "$"
    return bulls, cows

count = 0
while True:
    guess = input()
    if guess == "GIVE UP":
        print(f"The word was not guessed. Answer: {target}.")
        break
    bulls, cows = score(guess)
    bulls_word = "bull" if bulls == 1 else "bulls"
    cows_word = "cow" if cows == 1 else "cows"
    print(f"{guess} Score {bulls} {bulls_word} and {cows} {cows_wor}.")
    count += 1
    if guess == target:
        print(f"The word was guessed in {count}.")
        break
