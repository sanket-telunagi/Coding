n = int(input())
vals = []

for i in range(1, n + 1):
    if i % 2 == 0:
        vals.append("I love")
    else:
        vals.append("I hate")

print(" that ".join(vals) + " it")
