def findAllConcatenatedWordsInADict(words: list[str]) -> list[str]:
    s = set()
    concatenateWords = []
    for word in words:
        s.add(word)
    for word in words:
        if checkConcatenate(word, s) == True:
            concatenateWords.append(word)
    return concatenateWords
def checkConcatenate(word: str, s: set) -> bool:
    for i in range(1, len(word)):
        prefixWord = word[:i]
        suffixWord = word[i:]
        if prefixWord in s and (suffixWord in s or checkConcatenate(suffixWord, s)):
            return True
    return False

words = input().split(" ")
print(findAllConcatenatedWordsInADict(words))