T = int(input())

def battle(c, l, m, r):
    i, j, idx = l, m+1, l

    while i<=m and j<r:
        if c[i] == c[j]:
            return i
        elif c[i] > c[j]:
            if c[j] == 2:
                return i
            else:
                return j
        else:
            if c[i] == 2:
                return j
            else:
                return i

def rsp(c, l, r):
    if l < r:
        middle = (l + r) // 2
        if middle - l == 1:
            stack.append([l, middle])
            rsp(c, middle + 1, r)
        if r == middle:
            stack.append([r])
            rsp(c, l, middle)
            if r == 1:
                print(r, stack)
    else:
        stack.append([l])
        return



for t in range(1, T+1):
    N = int(input())
    card = list(map(int, input().split()))
    stack = []
    rsp(card, 0, N-1)
    print(stack)

