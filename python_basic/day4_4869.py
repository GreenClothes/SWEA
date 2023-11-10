T = int(input())

cnt = 0
def dfs(n):
    if n <= 0:
        return 1
    d_cnt = 0
    if n >= 10:
        d_cnt += 1 * dfs(n-10)
    if n >= 20:
        d_cnt += 2 * dfs(n-20)
    return d_cnt


for t in range(1, T+1):
    N = int(input())
    cnt = 0

    if N <= 10:
        cnt = 1
    else:
        cnt = dfs(N-10) + 2 * dfs(N-20)

    print('#{0} {1}'.format(t, cnt))
