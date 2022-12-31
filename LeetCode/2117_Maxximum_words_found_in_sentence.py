
def mostWordsFound(sentences) -> int :
    ct = -1 
    for i in sentences :
        ct = max(ct,len(i.split()))
    return ct 


sentences = input().split(",")

print(mostWordsFound(sentences))
