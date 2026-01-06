def solution(N, S):
    # Write your code here
    res = 0
    curr = 0
    for i in S:
        if i == "1":
            curr += 1
            res = max(res, curr)
        else:
            curr = 0
    return res


T = int(input())
for _ in range(T):
    N = int(input())
    S = input()

    out_ = solution(N, S)
    print(out_)
