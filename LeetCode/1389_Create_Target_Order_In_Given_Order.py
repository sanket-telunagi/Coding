from typing import List
def createTargetArray(nums: List[int], index: List[int]) -> List[int]:
    ans = []
    for idx, num in zip(index, nums) :
        ans.insert(idx, num)
    return ans

nums = map(int, input().split())
index = map(int, input().split())
print(*createTargetArray(nums, index))