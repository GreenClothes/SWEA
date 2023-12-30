T = int(input())

for _ in range(T):
    t = int(input())
    student = list(map(int, input().split()))
    cnt = [[0, n] for n in range(101)]
    for score in student:
        cnt[score][0] += 1
    print('#{0} {1}'.format(t, sorted(cnt)[-1][1]))