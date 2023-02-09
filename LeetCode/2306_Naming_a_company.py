import collections
def distinctNames(ideas : list[str]) -> int :

    wordMap = collections.defaultdict(set)

    for name in ideas :
        wordMap[name[0]].add(name[1:])
    
    ans = 0 

    for ch1 in wordMap :
        for ch2 in wordMap :
            if ch1 == ch2 : continue

            common = 0 

            for word in wordMap[ch1] :
                if word in wordMap[ch2] :
                    common += 1
            
            d1 = len(wordMap[ch1]) - common
            d2 = len(wordMap[ch2]) - common
        
            ans += d1 * d2
    
    return ans 