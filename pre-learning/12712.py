T = int(input())

for t in range(1, T+1):
    N, M = map(int, input().split())
    bug = [list(map(int, input().split())) for _ in range(N)]
    dx1 = [-1, 0, 1, 0]
    dy1 = [0, -1, 0, 1]
    dx2 = [-1, 1, 1, -1]
    dy2 = [-1, -1, 1, 1]
    ans = 0

    for i in range(N):
        for j in range(N):
            temp1 = 0
            temp2 = 0

            for dm in range(M):
                if dm:
                    for k in range(4):
                        di = i + dy1[k] * dm
                        dj = j + dx1[k] * dm
                        if 0<=di<N and 0<=dj<N:
                            temp1 += bug[di][dj]

                        di = i + dy2[k] * dm
                        dj = j + dx2[k] * dm
                        if 0 <= di < N and 0 <= dj < N:
                            temp2 += bug[di][dj]
                else:
                    temp1 += bug[i][j]
                    temp2 += bug[i][j]
            ans = max(ans, temp1)
            ans = max(ans, temp2)
    print("#{0} {1}".format(t, ans))
