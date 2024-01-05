T = int(input())

for t in range(1, T+1):
    N = int(input())
    HOUSE = list(map(int, input().split()))
    dp = [1] * N

    for i in range(1, N):
        for j in range(i, -1, -1):
            if HOUSE[j] < HOUSE[i]:
                dp[i] = max(dp[i], dp[j]+1)

    print('#{0} {1}'.format(t, N-max(dp)))