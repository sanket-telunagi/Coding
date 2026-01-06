# cook your dish here
_ = int(input())
for __ in range(_):
    n = int(input())
    nums = list(map(int, input().split()))
    # print(nums)
    total = sum(nums)

    d = total // (n - 1)

    res = []
    for i in range(n):
        res.append(d - nums[i])

    print(*res)
