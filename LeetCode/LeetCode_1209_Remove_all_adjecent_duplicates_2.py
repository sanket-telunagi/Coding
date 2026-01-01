def __result(s, k):
    stk = []
    for ch in s:
        stk.append(ch)
        if len(stk) >= k:
            while len(set(stk[-k:])) == 1:
                n = k
                while len(stk) >= 1 and n > 0:
                    stk.pop()
                    n -= 1

    return "".join(stk)


if __name__ == "__main__":
    s1 = "abcd"
    k1 = 2
    print(__result(s1, k1))

    s2 = "deeedbbcccbdaa"
    k2 = 2
    print(__result(s2, k2))

    s3 = "pbbcggttciiippooaais"
    k3 = 2
    print(__result(s3, k3))
