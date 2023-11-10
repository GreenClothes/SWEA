T = int(input())

for t in range(1, T+1):
    str1 = input().strip()
    str2 = input().strip()
    next = [0 for _ in range(len(str1))]
    for i, c in enumerate(str1):
        if str1.index(c) == i and next[i-1] == 0:
            next[i] = 0
        else:
            if str1[i-1] == str1[next[i-1]]:
                next[i] = next[i-1]+1
            else:
                next[i] = 0

    ans = 0
    i = 0
    while i < len(str2)-len(str1)+1:
        if str1[0] == str2[i]:
            for j in range(1, len(str1)):
                if str1[j] != str2[i+j]:
                    j = next[j]
                    break
                if j == len(str1)-1:
                    ans = 1
                    break
        if ans == 1:
            break
        i += 1

    print("#{0} {1}".format(t, ans))
