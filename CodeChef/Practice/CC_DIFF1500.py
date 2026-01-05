def solve():
    n = int(input())
    goals = list(map(int, input().split()))

    if n < 2:
        print("UNFIT")
        return

    max_diff = 0
    min_so_far = goals[0]

    for i in range(1, n):
        max_diff = max(max_diff, goals[i] - min_so_far)
        min_so_far = min(min_so_far, goals[i])

    if max_diff > 0:
        print(max_diff)
    else:
        print("UNFIT")


t = int(input())
for _ in range(t):
    solve()
