t = int(input())
while(t) :
    n, flips = map(int, input().split())
    din = input()
    num = int(din,base=2)
    
    while flips != 0 :

    # only add zeros 
        if (num << 1) > num :
            num <<= 1
            flips -= 1
        else :
            flips -= 1
    
    print(bin(num).replace("0b",""))

    

    t -= 1