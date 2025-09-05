def countBits(n : int) -> list[int] : 
    l = [] 
    for i in range(n+1) :
        l.append(bin(i).count('1'))
    return l

n = int(input())

print(*countBits(n))