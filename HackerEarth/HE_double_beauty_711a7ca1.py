_ = int(input())
for __ in range(_):
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))

    nums.sort(reverse=True)

    print(sum(nums[:k]) * 2)
