from typing import List 
def wordSubsets(words1: List[str], words2: List[str]) -> List[str]:
        word1hash = {}
        for word in words1 : 
            word1hash[word] = {}
            for letter in word :
                word1hash[word].setdefault(letter,0)
                word1hash[word][letter] += 1
        
        words2hash = {}
        for word in words2 : 
            words2hash[word] = {}
            for letter in word : 
                words2hash[word].setdefault(letter,0)
                words2hash[word][letter] += 1
        
        result = []
        for word , hash1 in word1hash.items() :
            
            isUniversal = True
            for compareword, hash2 in words2hash.items() :
                # print(word,word1hash[word],"\n",compareword,hash2, sep=" ")
                
                for letter, freq in hash2.items() :
                    if letter not in hash1.keys() : 
                        isUniversal = False 
                        break
                    # print(hash1[letter], freq)
                    if hash1[letter] < freq :
                        isUniversal = False
                        break 
                if not isUniversal : break
            if isUniversal :
                result.append(word)


        return result


words1 = input().split()
words2 = input().split()

result = wordSubsets(words1, words2)
print(*result)