def detectCapitalUse(word: str) -> bool:
    if (word.isupper() or (word[:1].isupper() and word[1:].islower()) or word.islower()) : return True 
    else : return False 

def main() :
    word = input() 
    print(detectCapitalUse(word))
if __name__ == "__main__" :
    main()
