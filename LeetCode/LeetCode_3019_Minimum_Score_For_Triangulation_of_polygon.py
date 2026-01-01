from itertools import combinations


# nums = list(map(int, input.split()))
def __result(nums):
    # # print triangles
    # n = len(nums)
    # res = 1e9
    # values = set()
    # pos_combo = n - 2
    # for i in range(pos_combo):
    #     temp = 0
    #     for j in range(2, n):
    #         start = i
    #         end = (start + j) % n
    #         mid = end - 1 % n
    #         print(nums[start], nums[mid], nums[end])
    #         temp += nums[start] * nums[mid] * nums[end]
    #     print("*****")
    #     res = min(res, temp)
    # # all_combo = combinations(values, pos_combo)
    # # print(*all_combo, sep="\n")
    #
    res = 1e9
    n = len(nums)
    triangles = list(combinations(nums, 3))

    def isValied(a, b, c, d):
        res = True
        for p, q, r in [a, b, c, d]:
            if not (p + q > r and p + r > q and q + r > p):
                return False
        return True

    for a, b, c, d in combinations(triangles, n - 2):
        # if isValied(a, b, c, d):
        temp = 0
        for p, q, r in [a, b, c, d]:
            print(p, q, r)
            temp += p * q * r
        res = min(res, temp)
        # print(a, b, c, d)
    return res


if __name__ == "__main__":
    nums = [1, 3, 1, 4, 1, 5]
    # The minimum score triangulation is 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.
    nums2 = [1, 2, 3]
    nums3 = [3, 7, 4, 5]
    nums4 = [1, 2, 3, 4, 5, 6]
    nums5 = [1, 2, 3, 4]
    nums6 = [1, 2, 3]
    print(__result(nums))
