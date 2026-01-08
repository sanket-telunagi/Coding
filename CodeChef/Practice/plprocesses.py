for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))

    if n == 1:
        print(nums[0])

    elif n == 2:
        print(max(nums[0], nums[1]))

    else:
        total = sum(nums)
        prefix_sum = 0
        min_time = float("inf")

        for i in range(n + 1):
            first_processor_time = prefix_sum
            second_processor_time = total - prefix_sum

            max_time = max(first_processor_time, second_processor_time)

            min_time = min(min_time, max_time)

            if i < n:
                prefix_sum += nums[i]

        print(min_time)
