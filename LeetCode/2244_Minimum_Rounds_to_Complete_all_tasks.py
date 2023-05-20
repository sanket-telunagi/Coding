
def minimumRounds(tasks: list[int]) -> int:
    tasks_dict = {}
    for i in tasks :
        tasks_dict.setdefault(i,0) 
        tasks_dict[i] += 1

    ans = 0 
    for i in tasks_dict.values() :
        # if number exists only once then there is no way we can complete in 2 or 3 option 
        if i <= 1 : 
            return -1 

        # we can break to do 3 tasks and add the ans 
        elif i % 3 == 0 : 
            ans += i // 3

        # something to figerout it just worked
        elif i == 2 : 
            ans += 1

        # same as above
        else :
            ans += (i // 3 + 1)

    return ans


if __name__ == "__main__" :
    tasks = map(int, input().split())
    print(minimumRounds(tasks))