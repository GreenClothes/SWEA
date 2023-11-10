T = int(input())

for t in range(1, T+1):
    str1 = list(set(input().strip()))
    str2 = input().strip()
    cnt = [0 for _ in range(len(str1))]

    for i in range(len(str2)):
        if str2[i] in str1:
            cnt[str1.index(str2[i])] += 1
    print('#{0} {1}'.format(t, max(cnt)))

