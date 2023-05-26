def search(s: str, ptr : str) :
    l, res, k = 0, 0, len(ptr)
    ptr_hsh, match = [0]*26, [0] * 26

    for ch in ptr : ptr_hsh[ord(ch) - ord('a')] += 1

    for idx , ch in enumerate(s) :
        if idx < k : match[ord(ch) - ord('a')] += 1 
        else : 
            match[ord(s[idx - k]) - ord('a')] -= 1
            match[ord(s[idx]) - ord('a')] += 1
        if match == ptr_hsh :
            
            # print(s[idx-k+1 : idx+1])
            res += 1


    return res 


if __name__ == "__main__" :
    s, ptr = input().split()
    print(search(s, ptr))

