x, y, z = map(int, input().split())


def _result(x, y, z):
    if abs(x - z) == abs(y - z):
        return 0
    elif abs(x - z) < abs(y - z):
        return 1
    return 2


print(_result(x, y, z))
