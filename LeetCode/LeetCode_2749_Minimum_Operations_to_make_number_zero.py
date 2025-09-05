num1, num2 = map(int, input().split())


def _result(num1, num2):
    for i in range(1, 33):
        x = num1 - (i * num2)
        if x < i:
            return -1
        if x.bit_count() <= i:
            return i


print(_result(num1, num2))
