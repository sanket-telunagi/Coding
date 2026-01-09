n = int(input())
li = list(input().split())
nl = []
for i in range(10):
    count = 0
    i = str(i)
    for x in li:
        if i in x:
            count += 1
        else:
            pass
    nl.append(count)
print(max(nl))
