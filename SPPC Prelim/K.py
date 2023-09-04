n = int(input())
prog = [input() for _ in range(n)]

def complexity(prog):
    if len(prog) == 0:
        return 1
    
    comp = 0

    if_start = 1
    while if_start < len(prog):
        # Find if body, else body
        if_end = if_start
        stack = 0
        while True:
            if prog[if_end] == "if":
                stack += 1
            elif prog[if_end] == "endif":
                stack -= 1
            elif prog[if_end] == "else" and stack == 0:
                break
            if_end += 1
        if_block = prog[if_start:if_end]

        else_start = if_end + 1
        else_end = else_start
        stack = 1
        while True:
            if prog[else_end] == "if":
                stack += 1
            elif prog[else_end] == "endif":
                stack -= 1
                if stack == 0:
                    break
            else_end += 1
        else_block = prog[else_start:else_end]

        if_start = else_end + 2

        comp = max(comp, complexity(if_block) + complexity(else_block))

    
    return comp
    


print(complexity(prog))
