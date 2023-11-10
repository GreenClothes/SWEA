T = int(input())

for t in range(1, T+1):
    s = list(input())

    i = 1
    while 1:
        if s[i] == s[i-1]:
            del s[i]
            del s[i-1]
            i -= 1
        else:
            i += 1
        if i == len(s) or len(s) == 0:
            break

    print('#{0} {1}'.format(t, len(s)))