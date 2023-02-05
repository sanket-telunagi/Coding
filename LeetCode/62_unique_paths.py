def fact(x : int) :
    if (x == 0 or x == 1) :
        return 1
    ans = 1
    for i in range(2,x+1) :
        ans *= i
    return ans 

def uniquePaths( m: int, n: int) -> int:
    return round((fact(m + n - 2)) / (fact(m-1) * fact(n-1)))

m,n = map(int, input().split())
print(uniquePaths(m , n))