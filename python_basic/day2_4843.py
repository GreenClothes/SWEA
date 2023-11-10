T = int(input())

for t in range(1, T+1):
    N = int(input())
    a = sorted(list(map(int, input().strip().split())))

    a_sort = []

    for i in range(1, 6):
        a_sort.append(a[-i])
        a_sort.append(a[i-1])
    print('#{}'.format(t), end=' ')
    print(*a_sort)