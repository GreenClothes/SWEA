T = int(input())

def find(table, n, m):
    ans = ''
    for i in range(n):
        for j in range(n-m+1):
            for l in range(m):
                ans += table[i][j+l]
            for k in range(m//2):
                if ans[k] != ans[-k-1]:
                    ans = ''
                    break
                if k == m//2-1:
                    return ans
            for l in range(m):
                ans += table[j + l][i]
            for k in range(m//2):
                if ans[k] != ans[-k-1]:
                    ans = ''
                    break
                if k == m//2-1:
                    return ans

for t in range(1, T+1):
    N, M = map(int, input().strip().split())
    C = [input().strip() for _ in range(N)]

    print('#{0} '.format(t), end='')
    print(find(C, N, M))

