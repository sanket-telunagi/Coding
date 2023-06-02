if __name__ == "__main__" :

    t = int(input())

    for i in range(t) :
        n = int(input())
        nums = list(map(int, input().split()))
        res = 1 
        for idx, num in enumerate(nums) :
            
            
            if (idx + 1) < n : 
                res = max(res, nums[idx] * nums[idx+1])
        
        print(res)