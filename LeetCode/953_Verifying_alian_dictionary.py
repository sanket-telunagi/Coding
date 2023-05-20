def isAlienSorted(words: list[str], order: str) -> bool:
    
    for i in range(min()) :
        if order.index(com[i]) > order.index(com[i+1]) :
            return False
    return True

words = input().split()
order = input()
print(isAlienSorted(words, order))