T = int(input())
A = [i for i in range(1, 13)]
print(A)

for t in range(1, T+1):
    N, K = map(int, input().strip().split())
    cnt = 0

    for i in range(1<<len(A)):
        subset = []
        for j in range(len(A)):
            if i & (1<<j):
                subset.append(A[j])
        if sum(subset) == K and len(subset) == N:
            cnt += 1
    print('#{0} {1}'.format(t, cnt))