from typing import List
def maxIceCream(self, costs: List[int], coins: int) -> int:
    costs.sort() 
    ct = 0 
    for i in costs :
        if coins == 0 : break
        else :
            if i <= coins :
                coins -= i
                ct += 1
    return ct 
