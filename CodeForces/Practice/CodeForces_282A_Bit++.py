n = int(input())

z = 0
for _ in range(n):
    operation = input().strip()
    if operation == "X++" or operation == "++X":
        z += 1
    else:
        z -= 1
print(z)
