def ret_max_sum(nums : list, k : int) :

    l, res, sum = 0, 0, 0
    for r, num in enumerate(nums) :

        while(r - l + 1 < k) :

            sum += num
            r += 1
        
        # sum += num
        res = max(res, sum)
        sum -= num
        l += 1
        return res

if __name__ == "__main__" :
    n, k = map(int,input().split())
    nums = (map(int, input().split()))
    print(ret_max_sum(nums, k))


