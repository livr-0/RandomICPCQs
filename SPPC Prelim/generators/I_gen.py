for x in range(1, 2**4):
    xs = bin(x)[2:]
    for y in range(1, x + 2):
        ys = bin(y)[2:]
        if ys not in xs:
            print(xs, ys)
            break
