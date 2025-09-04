import math

def solve():
    t = int(input())  # Read the number of test cases
    for _ in range(t):
        n = int(input())  # Number of sheep
        a = list(map(int, input().split()))  # The beauty levels of the sheep
        
        # Calculate all pairwise differences and find the gcd of all differences
        max_gcd = 0
        for i in range(n):
            for j in range(i + 1, n):
                diff = abs(a[i] - a[j])
                max_gcd = math.gcd(max_gcd, diff)
        
        # Output the maximum gcd for this test case
        print(max_gcd)

solve()