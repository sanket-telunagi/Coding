import math
def isValid(num) -> bool:
    val = []
    val.extend(str(num))
    digitSum = sum(list(map(int, val)))
    gcd = math.gcd(num, digitSum)
    return gcd != 1
for _ in range(int(input())) :
    num = int(input())
    
    while not isValid(num) :
        num += 1
    print(num)
