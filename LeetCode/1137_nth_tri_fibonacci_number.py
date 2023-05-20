dp = [-1]*(10**3)
def triboancci(n : int) :
    if (n == 0 or n == 1) : return n 
    if (n == 2) : return 1
    if (dp[n] != -1) : return dp[n]
    dp[n] = triboancci(n-1) + triboancci(n-2) + triboancci(n-3)
    return dp[n]

n = int(input())
print(triboancci(n))