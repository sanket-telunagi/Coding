ans  = []

def genPermute(nums,index = 0):
    global ans 
    if (index >= len(nums)) :
        ans.append(nums)
        print(*nums)
        return 
    for i in range(index, len(nums)) :
        nums[i], nums[index] = nums[index], nums[i]
        (genPermute(nums, index + 1))
        nums[i], nums[index] = nums[index], nums[i]


def permute(nums) :
    genPermute(nums)
    for i in ans :
        print(i)

if __name__ == "__main__" :
    nums = input().split()
    # print(*permute(nums))
    permute(nums)
 