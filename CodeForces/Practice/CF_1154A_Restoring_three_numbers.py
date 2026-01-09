nums = list(map(int, input().split()))
nums.sort()
a = nums[3] - nums[1]
b = nums[3] - nums[0]
c = nums[3] - nums[2]
print(*[a, b, c])
