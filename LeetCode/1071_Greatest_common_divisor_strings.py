import math
def gcdOfStrings(str1: str, str2: str) -> str:
    ans = ""
    if (str1 + str2 == str2 + str1) :
        ans = str1[:math.gcd(len(str1), len(str2))]
    return ans

str1, str2 = input().split()
print(gcdOfStrings(str1,str2))