# IF I EVER SEE ANYONE DO ANY OF THE THINGS IN THIS FILE IN A REAL LANGUAGE,
# I WILL REVOKE YOUR COMPUTER PRIVILEGES FOREVER.

import sys

tokens = sys.stdin.read().split()
funcs = []
funcdefs = []
KWS = ["if", "then", "else"]

for i, tok in enumerate(tokens):
    if tok == "func":
        funcs.append(tokens[i + 1])

def read_funcs():
    assert(tokens.pop(0) == "func")
    name = tokens.pop(0)
    assert(tokens.pop(0) == "(")
    args = []
    while tokens[0] != ")":
        args.append(tokens.pop(0))
        if tokens[0] == ",":
            assert(tokens.pop(0) == ",")
    assert(tokens.pop(0) == ")")
    innerfuncs = []
    body = []
    while tokens[0] != "end":
        if tokens[0] == "func":
            innerfuncs += read_funcs()
        else:
            body.append(tokens.pop(0))
    assert(tokens.pop(0) == "end")
    return [(name, args, body)] + innerfuncs


while tokens:
    funcdefs += read_funcs()


all_inserts = {}
all_calls = {}
all_args = {}
reprocess = set()
for func in funcdefs:
    inserts = set()
    calls = set()
    for tok in func[2]:
        if tok.isalpha() and tok not in KWS:
            if tok not in funcs and tok not in func[1]:
                inserts.add(tok)
            elif tok in funcs:
                calls.add(tok)
                reprocess.add(tok)
    all_inserts[func[0]] = inserts
    all_calls[func[0]] = calls
    all_args[func[0]] = func[1]

while reprocess:
    name = reprocess.pop()
    for f in funcs:
        init = len(all_inserts[f])
        if name in all_calls[f]:
            for insert in all_inserts[name]:
                if insert not in all_args[f]:
                    all_inserts[f].add(insert)
        if init != len(all_inserts[f]):
            reprocess.add(f)

for k, v in all_inserts.items():
    all_inserts[k] = list(sorted(v))

def fixtoks(toks):
    new_toks = []
    n = 0
    while n < len(toks):
        tok = toks[n]
        if tok in funcs:
            new_toks.append(tok)
            new_toks.append("(")
            if all_inserts[tok]:
                new_toks.append(" , ".join(all_inserts[tok]))
                if toks[n + 2] != ")":
                    new_toks[-1] += " ,"
            n += 2
            paren = 1
            func_toks = []
            while True:
                if toks[n] == "(":
                    func_toks.append(toks[n])
                    paren += 1
                elif toks[n] == ")":
                    func_toks.append(toks[n])
                    paren -= 1
                    if paren == 0:
                        break
                else:
                    func_toks.append(toks[n])
                n += 1
            new_toks += fixtoks(func_toks)
        else:
            new_toks.append(tok)
        n += 1
    return new_toks

outfuncs = []
for func in funcdefs:
    args = all_inserts[func[0]] + func[1]
    args_str = " , ".join(args)
    print(f"func {func[0]} ( {args_str} )")
    print(" ".join(fixtoks(func[2])))
    print("end")
