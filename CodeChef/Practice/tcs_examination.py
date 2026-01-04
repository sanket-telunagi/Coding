# cook your dish here
_ = int(input())
for __ in range(_):
    dragon = list(map(int, input().split()))
    sloth = list(map(int, input().split()))

    # total marks
    if sum(dragon) == sum(sloth):
        # dsa marks
        if dragon[0] == sloth[0]:
            # toc marks
            if dragon[1] == sloth[1]:
                # DM marks
                if dragon[2] == sloth[2]:
                    # everything is same its tie
                    print("TIE")
                else:
                    print("DRAGON" if dragon[2] > sloth[2] else "SLOTH")
            else:
                print("DRAGON" if dragon[1] > sloth[1] else "SLOTH")
        else:
            print("DRAGON" if dragon[0] > sloth[0] else "SLOTH")
    else:
        print("DRAGON" if sum(dragon) > sum(sloth) else "SLOTH")
