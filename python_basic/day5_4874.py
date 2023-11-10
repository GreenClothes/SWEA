T = int(input())

def cal(code):
    stack = []

    for i in range(len(code)-1):
        try:
            stack.append(int(c[i]))
        except ValueError:
            if len(stack) >= 2:
                if c[i] == '+':
                    result = stack[-2] + stack[-1]
                    stack.pop(); stack.pop()
                    stack.append(result)
                elif c[i] == '-':
                    result = stack[-2] - stack[-1]
                    stack.pop(); stack.pop()
                    stack.append(result)
                elif c[i] == '*':
                    result = stack[-2] * stack[-1]
                    stack.pop(); stack.pop()
                    stack.append(result)
                elif c[i] == '/':
                    result = stack[-2] // stack[-1]
                    stack.pop(); stack.pop()
                    stack.append(result)
            else:
                return 'error'
    if len(stack) == 1:
        return stack[0]
    else:
        return 'error'

for t in range(1, T+1):
    c = list(input().split())

    print('#{0} {1}'.format(t, cal(c)))