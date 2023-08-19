for _ in range(3):
    x, y = (int(v) for v in input().split())
    if x == y:
        print(f"Doubles. Move forwards {x + y} squares.")
        break
else:
    has_card = input() == "y"
    if has_card:
        print(f"Use card. Move forwards {x + y} squares.")
    else:
        print(f"$50 fine. Move forwards {x + y} squares.")
