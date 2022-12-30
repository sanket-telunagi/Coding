dp = [-1]*30

def fibo(n : int) -> int :
    if ( n == 0 or n == 1) : return n 
    if (dp[n] != -1) : return dp[n]
    dp[n] = fibo(n-1) + fibo(n-2)
    return dp[n]

n = int(input())
print(fibo(n))
