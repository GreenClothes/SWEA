T = int(input())

def search(l, r, P):
    cnt = 1
    while 1:
        s = (l+r)//2
        if s == P:
            return cnt
        elif s < P:
            l = s
        else:
            r = s
        cnt += 1


for t in range(1, T+1):
    P, Pa, Pb = map(int, input().strip().split())

    cnt_a = search(1, P, Pa)
    cnt_b = search(1, P, Pb)

    if cnt_a == cnt_b:
        win = 0
    elif cnt_a < cnt_b:
        win = 'A'
    else:
        win = 'B'

    print('#{0} {1}'.format(t, win))