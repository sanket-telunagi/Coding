
from typing import List

# def totalCost(costs: List[int], k: int, candidates: int) -> int:

#     res = 0 

#     for repeat in range(k) :

#         first_k = min(costs[:candidates])
#         print(*costs[:candidates])
    

#         last_k = min(costs[-candidates:])
#         print(*costs[-candidates:])
#         print(first_k, last_k, sep=" ")

        

#         mn = min(first_k, last_k )
#         res += mn


#         print(res)
#         print("--------")

#         if first_k == last_k :
#             costs.remove(mn)
        
#         else :

#             costs.reverse()
#             index = costs.index(mn)
#             costs.reverse()
#             np.delete()


#     return res 

import numpy as np

def totalCost(costs: List[int], k: int, candidates: int) -> int:

    res = 0 
    costs_np = np.array(costs)
    for repeat in range(k) :
        first_k = np.min(costs_np[:candidates])
        # print(*costs[:candidates])
    

        last_k = np.min(costs_np[-candidates:])
        # print(*costs[-candidates:])
        # print(first_k, last_k, sep=" ")

        

        mn = np.min([first_k, last_k] )
        res += mn


        # print(res)
        # print("--------")

        if first_k == mn :
            # remove first occurance from the first candidates 
            np.delete(costs_np,costs.index(mn))
        
        elif last_k == mn :
            # remove last occurance from last first candidates
            costs.reverse()
            index = np.where(costs_np)
            costs.reverse()

            np.delete(costs_np, index)

        else :

            np.delete(costs_np,costs.index(mn))



        
    return res 


if __name__ == "__main__" :

    costs = list(map(int, input().split()))
    k, candidates = map(int, input().split()) 
    print(totalCost(costs, k, candidates))