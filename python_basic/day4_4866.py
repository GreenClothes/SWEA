T = int(input())

def check(str):
    stack = []
    o = ['(', '{', '[']
    c = [')', '}', ']']

    for s in str:
        if s in o:
            stack.append(s)
        if s in c:
            if len(stack) == 0:
                return 0
            elif c.index(s) == o.index(stack[-1]):
                stack.pop()
            else:
                return 0
    if len(stack) > 0:
        return 0
    else:
        return 1

for t in range(1, T+1):
    code = input()

    print('#{0} {1}'.format(t, check(code)))
