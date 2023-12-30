T = int(input())

for t in range(1, T+1):
    NM = list(map(int, input().split()))
    AB = [list(map(int, input().split())) for _ in range(2)]
    sums = []
    if NM[0] > NM[1]:
        max_idx = 0
    else:
        max_idx = 1
    min_idx = int(not max_idx)

    for i in range(NM[max_idx]-NM[min_idx]+1):
        temp = 0
        for j in range(NM[min_idx]):
            temp += AB[max_idx][i+j] * AB[min_idx][j]
        sums.append(temp)
    print('#{0} {1}'.format(t, max(sums)))

