T = int(input())

for test_case in range(1, T + 1):
    N = int(input())
    area = [[0 for _ in range(10)] for _ in range(10)]
    cnt = 0
    for _ in range(N):
        c = list(map(int, input().strip().split()))
        if c[-1] == 1:
            for i in range(c[0], c[2]+1):
                for j in range(c[1], c[3]+1):
                    area[i][j] += 1
                    if area[i][j] == 3:
                        cnt += 1
        else:
            for i in range(c[0], c[2]+1):
                for j in range(c[1], c[3]+1):
                    area[i][j] += 2
                    if area[i][j] == 3:
                        cnt += 1
    print('#{0} {1}'.format(test_case, cnt))
